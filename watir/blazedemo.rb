require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://blazedemo.com'

browser.button(:value => "Find Flights").click()

table = browser.table(:class => "table")

table[-1].button(:type => "submit").click()

browser.text_fields.each do |field|
  field.set("test")
end

browser.checkbox(:id => "rememberMe").set

browser.button(:value => "Purchase Flight").click()
