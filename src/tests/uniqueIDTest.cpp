#include "../../include/uniqueIDTest.hh"
#include "../../include/GEDValidityTests.hh"

void UniqueIDTest::setUp(){
	//test bbd is a modified ged file, first person has a birth after a death, second a brith before death, thrid no brith date and fourth no deathdate
	//there is more data left in the file, there isn't any particular reason to take it out
	testReaderValidGED =  new GEDData("MyFamily.ged");
    testReaderInvalidGED = new GEDData("testbbd.ged");

}
void UniqueIDTest::tearDown(){
	delete testReaderValidGED;
	delete testReaderInvalidGED;

}
void UniqueIDTest::testAllUniqueIds(){
    vector< vector<int> * > data = GEDValidityTests::checkValidUniqueID(testReaderValidGED);
	CPPUNIT_ASSERT_MESSAGE("found same id's although all were unique",
        (* data[0]).size() == 0 && (* data[1]).size() ==0);

}

void UniqueIDTest::testIndividualNonUniqueIds(){
    vector< vector<int> * > data = GEDValidityTests::checkValidUniqueID(testReaderInvalidGED);
	CPPUNIT_ASSERT_MESSAGE("indiduvals with same id not caught",
        (* data[0]).size() != 0);

}

void UniqueIDTest::testFamilyNonUniqueIds(){
    vector< vector<int> * > data = GEDValidityTests::checkValidUniqueID(testReaderInvalidGED);
	CPPUNIT_ASSERT_MESSAGE("families with same id not caught",
        (* data[1]).size() != 0);

}
