#include "../../include/tests.hh"


void DateTest::setUp(){
	testDate = new Date();	
	testDateTwo = new Date(10,12,2017);	
	testDateThree = new Date(10,12,2017);	
}
void DateTest::tearDown(){
	delete testDate, testDateTwo,testDateThree;
}
  //test to make sure that the tags are converted to 
void DateTest::testEquality(){
	CPPUNIT_ASSERT((*testDateTwo) == (*testDateThree));
}
void DateTest::testDateValid(){
	//a valid date tag
	vector<string> * validTag = new vector<string>;

	validTag->push_back("2");
	validTag->push_back("DATE");
	validTag->push_back("25 MAY 1959");

	Date * compareDate = new Date(12,5,1959);		
	testDate->setFromTag(validTag);
	CPPUNIT_ASSERT_MESSAGE("date not parsed from tag correctly",(*compareDate) == (*testDate));
}
void DateTest::testDateInvalidSyntax(){
	//a date tag which is not syntactically correct
	vector<string> *  invalidTagSyntax = new vector<string>;

	invalidTagSyntax->push_back("x");
	invalidTagSyntax->push_back("BLAH");
	invalidTagSyntax->push_back("25 MAY 1959");
	try{
		testDate->setFromTag(invalidTagSyntax);	
	}catch(const char* message){
		CPPUNIT_ASSERT(true);	
	}
	CPPUNIT_FAIL("invalid syntax was accepted");
}
void DateTest::testDateDayTooHigh(){
	//checking that the upper bounds of the days are valid
	vector<string> *  invalidTagDayTooHigh = new vector<string>;

	invalidTagDayTooHigh->push_back("2");
	invalidTagDayTooHigh->push_back("DATE");
	invalidTagDayTooHigh->push_back("25 MAY 1959");
	try{
		testDate->setFromTag(invalidTagDayTooHigh);	
	}catch(const char* message){
		CPPUNIT_ASSERT(true);	
	}
	CPPUNIT_FAIL("accepted day past upper bound");
}
void DateTest::testDateDayTooLow(){
	vector<string> *  invalidTagDayTooLow = new vector<string>;

	invalidTagDayTooLow->push_back("2");
	invalidTagDayTooLow->push_back("DATE");
	invalidTagDayTooLow->push_back("25 MAY 1959");
	try{
		testDate->setFromTag(invalidTagDayTooLow);	
	}catch(const char* message){
		CPPUNIT_ASSERT(true);	
	}
	CPPUNIT_FAIL("accepted day lower than lower bound");
}
void DateTest::testDateInvalidMonth(){
	//checking to see if months are correctly changed
	vector<string> *  invalidTagNotARealMonth = new vector<string>;

	invalidTagNotARealMonth->push_back("2");
	invalidTagNotARealMonth->push_back("DATE");
	invalidTagNotARealMonth->push_back("25 MAY 1959");
	try{
		testDate->setFromTag(invalidTagNotARealMonth);	
	}catch(const char* message){
		CPPUNIT_ASSERT(true);	
	}
	CPPUNIT_FAIL("accepted month that does not exist");
}
void DateTest::testDateInvalidYear(){
	//checking to see that years are valid
	vector<string> *  invalidTagYearLessThanZero = new vector<string>;

	invalidTagYearLessThanZero->push_back("2");
	invalidTagYearLessThanZero->push_back("DATE");
	invalidTagYearLessThanZero->push_back("25 MAY 1959");
	try{
		testDate->setFromTag(invalidTagYearLessThanZero);	
	}catch(const char* message){
		CPPUNIT_ASSERT(true);	
	}
	CPPUNIT_FAIL("accepted year that is below 0");
}


