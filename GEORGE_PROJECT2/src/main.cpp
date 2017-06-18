#include "../include/GEDReader.hh"
#include "../include/tests.hh"

main(){
	cout<< "starting tests" << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(DateTest::suite());	
	runner.run();
	GEDReader AReader("MyFamily.ged");
	AReader.parseFile();
	AReader.outputToFile();
	return 0;
	
};
