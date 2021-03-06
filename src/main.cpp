#include "../include/GEDData.hh"
#include "../include/GEDWriter.hh"
#include "../include/DateTest.hh"
#include "../include/BirthBeforeDeathTest.hh"
#include "../include/isDeadTest.hh"
#include "../include/uniqueIDTest.hh"
#include "../include/GenderRoleTest.hh"
#include "../include/Date.hh"
#include <ctime>

void displayHelp(){
    cout << "Help: \n  correct useage is GEDReader <filename> <optional tags>" << endl;
    cout << "-t run unit tests before parsing file, no filename has to be specified when using the -t command"<< endl;
}
main(int argc, char * argv[]){
    //TODO implement silent and verbose tags
    Date today;
    cout<< "today is" + today.toString() << endl;
    bool shouldTest = true;
    bool help = false;
    if(argc < 2){
        cerr << "incorrect usage!, must include a filenmae, type --help for more info" <<endl;
    }
    if(argv[1] == "--help"){
        displayHelp();
        return 0;
    };
    for(int i = 1; i< argc; i++){
        if(argv[i] == "-t"){
            shouldTest = true;
        }
        if(argv[i] == "--help"){
            displayHelp();
            return 0;
        }
    }
    if(shouldTest){
        cout<< "starting tests" << endl;
        CppUnit::TextUi::TestRunner runner;
        runner.addTest(DateTest::suite());
        runner.addTest(BirthBeforeDeathTest::suite());
        runner.addTest(IsDeadTest::suite());
        runner.addTest(UniqueIDTest::suite());
        runner.addTest(GenderRoleTest::suite());
        runner.run();
    }
    if(argv[1] != "-t"){
        GEDData parsedFile(argv[1]);
        GEDWriter gedwriter(&parsedFile);
        gedwriter.writeNewGEDFile();
        gedwriter.writeOutputFile();
        gedwriter.listTheDead();
    }
	return 0;


};
