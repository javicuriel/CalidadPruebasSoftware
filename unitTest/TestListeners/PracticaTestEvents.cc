#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

using namespace std;

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;
using ::testing::TestInfo;
using ::testing::TestCase;

class EventListener : public EmptyTestEventListener{
  ofstream error_log;
public:
  virtual void OnTestProgramStart(const UnitTest&) {
    error_log.open ("error_log.txt");
    error_log << "Iniciando Test\n";
  }

  virtual void OnTestProgramEnd(const UnitTest& ut) {
    error_log << "El # de Tests ejecutados fue: " << ut.total_test_case_count() << endl;
    error_log << ut.successful_test_case_count() << " correctos\n";
    error_log << ut.failed_test_case_count() << " incorrectos\n";
    error_log.close();
  }

  virtual void OnTestPartResult(const TestPartResult& tpr) {
    error_log << "Falla. Los detalles son los siguientes: \n";
    error_log << tpr.summary() << endl;
  }

  virtual void OnTestStart(const TestInfo& ti) {
    error_log << "Test Case: " << ti.test_case_name()<< endl;
    error_log << "Test Name: " << ti.name()<< endl;
  }
  virtual void OnTestEnd(const TestInfo& ti) {
    error_log << "El tiempo de ejecuccion de "<< ti.name() <<" es de: " << ti.result()->elapsed_time() << "ms\n";
  }

  virtual void OnTestCaseEnd(const TestCase& tc) {
    error_log << "El tiempo de ejecuccion es de " << tc.name() <<" es de: " << tc.elapsed_time() << "ms\n";
  }
};

TEST(TcnOne,tname){
  ASSERT_EQ(1,-1);
}



int main(int argc, char *argv[]) {
  InitGoogleTest(&argc,argv);
  TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new EventListener);
  return RUN_ALL_TESTS();
}
