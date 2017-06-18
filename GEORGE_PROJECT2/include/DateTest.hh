#ifndef _DATETEST_H_
#define _DATETEST_H_

#include "GEDReader.hh" 
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>

using namespace CppUnit;

class DateTest : public CppUnit::TestFixture {
	private:
	  Date * testDate;
	  Date * testDateTwo; 
	  Date * testDateThree;
	public:
	void setUp();


	void tearDown(); 
	//test to make sure that the tags are converted to 
	void testEquality();
	void testDateValid();
	void testDateInvalidSyntax();
	void testDateDayTooHigh();
	void testDateDayTooLow();
	void testDateInvalidMonth();
	void testDateInvalidYear();
	  CPPUNIT_TEST_SUITE(DateTest);
	  CPPUNIT_TEST(testEquality);
	  CPPUNIT_TEST(testDateValid);
	  CPPUNIT_TEST(testDateInvalidSyntax);
	  CPPUNIT_TEST(testDateDayTooHigh);
	  CPPUNIT_TEST(testDateDayTooLow);
	  CPPUNIT_TEST(testDateInvalidMonth);
	  CPPUNIT_TEST(testDateInvalidYear);
	  CPPUNIT_TEST_SUITE_END();
};
#endif
