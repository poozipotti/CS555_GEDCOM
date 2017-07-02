#include "../include/GEDData.hh"
#include "../include/GEDWriter.hh"
#include "../include/DateTest.hh"
#include "../include/BirthBeforeDeathTest.hh"
#include "../include/isDeadTest.hh"

main(){
	cout<< "starting tests" << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(DateTest::suite());
	runner.addTest(BirthBeforeDeathTest::suite());
    runner.addTest(IsDeadTest::suite());
	runner.run();
	GEDData parsedFile("testbbd.ged");
    GEDWriter gedwriter(&parsedFile);
    gedwriter.writeNewFile();
    gedwriter.listTheDead();
	return 0;

};
