from selenium import webdriver
from selenium.webdriver.common.by import By
driver = webdriver.Firefox()

driver.get("http://localhost:4000/install/index.php")
driver.find_element(By.XPATH,'/html/body/div/div/div[1]/form/div[2]/div/input').click()
driver.find_element(By.XPATH,'/html/body/div/div/div[1]/form/div/div[2]/input').click()

driver.find_element(By.XPATH,'//*[@id="input-db-hostname"]').clear()
driver.find_element(By.XPATH,'//*[@id="input-db-hostname"]').send_keys("mysql")
driver.find_element(By.XPATH,'//*[@id="input-db-username"]').clear()
driver.find_element(By.XPATH,'//*[@id="input-db-username"]').send_keys("admin")
driver.find_element(By.XPATH,'//*[@id="input-db-password"]').send_keys("admin")
driver.find_element(By.XPATH,'//*[@id="input-db-database"]').send_keys("opencart")
driver.find_element(By.XPATH,'//*[@id="input-password"]').send_keys("admin")
driver.find_element(By.XPATH,'//*[@id="input-email"]').send_keys("admin@admin.com")
driver.find_element(By.XPATH,'/html/body/div/div/div[1]/form/div/div[2]/input').click()

driver.get("http://localhost:4000/admin/")

username = driver.find_element_by_id("input-username")
password = driver.find_element_by_id("input-password")
username.send_keys("admin")
password.send_keys("admin")

driver.find_element_by_css_selector('button.btn.btn-primary').click()
driver.find_element(By.XPATH,'//*[@id="modal-security"]/div/div/div[1]/button').click()

driver.find_element(By.XPATH,'//*[@id="menu-catalog"]/a').click()
driver.find_element(By.XPATH,'//*[@id="collapse1"]/li[2]/a').click()
driver.find_element(By.XPATH,'//*[@id="collapse1-1"]/li[1]').click()

driver.find_element(By.XPATH,'//*[@id="content"]/div[1]/div/div/a').click()
driver.find_element(By.XPATH,'//*[@id="input-name1"]').send_keys("product1")
driver.find_element(By.XPATH,'//*[@id="input-meta-title1"]').send_keys("product1")
driver.find_element(By.XPATH,'//*[@id="form-product"]/ul/li[2]/a').click()
driver.find_element(By.XPATH,'//*[@id="input-model"]').send_keys("ProductModel1")
driver.find_element(By.XPATH,'//*[@id="input-price"]').send_keys("1000")

driver.find_element(By.XPATH,'//*[@id="content"]/div[1]/div/div/button').click()

driver.find_element(By.XPATH,'//*[@id="content"]/div[1]/div/div/a').click()
driver.find_element(By.XPATH,'//*[@id="input-name1"]').send_keys("product2")
driver.find_element(By.XPATH,'//*[@id="input-meta-title1"]').send_keys("product2")
driver.find_element(By.XPATH,'//*[@id="form-product"]/ul/li[2]/a').click()
driver.find_element(By.XPATH,'//*[@id="input-model"]').send_keys("ProductModel2")
driver.find_element(By.XPATH,'//*[@id="input-price"]').send_keys("2000")
driver.find_element(By.XPATH,'//*[@id="content"]/div[1]/div/div/button').click()

driver.get("http://localhost:4000")

driver.find_element(By.XPATH,'//*[@id="search"]/input').send_keys("product1")
driver.find_element(By.XPATH,'//*[@id="search"]/div/button').click()
driver.find_element(By.XPATH,'//*[@id="content"]/div[3]/div[1]/div/div[2]/div[2]/button[1]').click()
driver.find_element(By.XPATH,'//*[@id="search"]/input').clear()
driver.find_element(By.XPATH,'//*[@id="search"]/input').send_keys("product2")
driver.find_element(By.XPATH,'//*[@id="search"]/div/button').click()
driver.find_element(By.XPATH,'//*[@id="content"]/div[3]/div[1]/div/div[2]/div[2]/button[1]').click()
