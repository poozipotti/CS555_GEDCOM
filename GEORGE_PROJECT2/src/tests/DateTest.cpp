#include "../../include/DateTest.hh"


void DateTest::setUp(){
	testDate = new Date();	
	testDateTwo = new Date(10,12,2017);	
	testDateThree = new Date(10,12,2017);	
	testDateFour =new Date(10,12,2016);
}

void DateTest::tearDown(){
	delete testDate, testDateTwo,testDateThree,testDateFour;
}
  //test to make sure that the tags are converted to 
void DateTest::testEquality(){
	CPPUNIT_ASSERT((*testDateTwo) == (*testDateThree));
}
void DateTest::testLessThan(){
	CPPUNIT_ASSERT((*testDateFour) < (*testDateTwo));
	testDateFour->setMonth(9);
	testDateFour->setYear(2017);
	CPPUNIT_ASSERT((*testDateFour) < (*testDateTwo));
	testDateFour->setMonth(10);
	testDateFour->setMonthDay(11);
	CPPUNIT_ASSERT((*testDateFour) < (*testDateTwo));
}
void DateTest::testGreaterThan(){
	CPPUNIT_ASSERT((*testDateTwo) > (*testDateFour));
	testDateFour->setMonth(9);
	testDateFour->setYear(2017);
	CPPUNIT_ASSERT((*testDateTwo) > (*testDateFour));
	testDateFour->setMonth(10);
	testDateFour->setMonthDay(11);
	CPPUNIT_ASSERT((*testDateTwo) > (*testDateFour));
}

void DateTest::testDateValid(){
	//a valid date tag
	vector<string> * validTag = new vector<string>;

	validTag->push_back("2");
	validTag->push_back("DATE");
	validTag->push_back("25 MAY 1959");

	Date * compareDate = new Date(5,25,1959);		
	try{
		testDate->setFromTag(validTag);
	}catch(const char* message){
		cout<< message << endl;
	}	
	CPPUNIT_ASSERT_MESSAGE("date not parsed from tag correctly",(*compareDate) == (*testDate));
}
void DateTest::testDateInvalidSyntax(){
	//a date tag which is not syntactically correct
	vector<string> *  invalidTagSyntax = new vector<string>;

	invalidTagSyntax->push_back("x");
	invalidTagSyntax->push_back("BLAH");
	invalidTagSyntax->push_back("25 MAY 1959");
	CPPUNIT_ASSERT_THROW(testDate->setFromTag(invalidTagSyntax),char*);	
}
void DateTest::testDateDayTooHigh(){
	//checking that the upper bounds of the days are valid
	vector<string> *  invalidTagDayTooHigh = new vector<string>;

	invalidTagDayTooHigh->push_back("2");
	invalidTagDayTooHigh->push_back("DATE");
	invalidTagDayTooHigh->push_back("100 MAY 1959");
	CPPUNIT_ASSERT_THROW(testDate->setFromTag(invalidTagDayTooHigh),char*);
}
void DateTest::testDateDayTooLow(){
	vector<string> *  invalidTagDayTooLow = new vector<string>;

	invalidTagDayTooLow->push_back("2");
	invalidTagDayTooLow->push_back("DATE");
	invalidTagDayTooLow->push_back("-2 MAY 1959");
	CPPUNIT_ASSERT_THROW(testDate->setFromTag(invalidTagDayTooLow),char*);
}
void DateTest::testDateInvalidMonth(){
	//checking to see if months are correctly changed
	vector<string> *  invalidTagNotARealMonth = new vector<string>;

	invalidTagNotARealMonth->push_back("2");
	invalidTagNotARealMonth->push_back("DATE");
	invalidTagNotARealMonth->push_back("25 POOP 1959");
	CPPUNIT_ASSERT_THROW(testDate->setFromTag(invalidTagNotARealMonth),char*);
}
void DateTest::testDateInvalidYear(){
	//checking to see that years are valid
	vector<string> *  invalidTagYearLessThanZero = new vector<string>;

	invalidTagYearLessThanZero->push_back("2");
	invalidTagYearLessThanZero->push_back("DATE");
	invalidTagYearLessThanZero->push_back("25 MAY -20");
	CPPUNIT_ASSERT_THROW(testDate->setFromTag(invalidTagYearLessThanZero),char*);
}


