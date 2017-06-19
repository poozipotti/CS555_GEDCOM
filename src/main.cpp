#include "../include/GEDReader.hh"
#include "../include/DateTest.hh"
#include "../include/BirthBeforeDeathTest.hh"

main(){
	cout<< "starting tests" << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(DateTest::suite());	
	runner.addTest(BirthBeforeDeathTest::suite());	
	runner.run();
	GEDReader AReader("testbbd.ged");
	return 0;
	
};
