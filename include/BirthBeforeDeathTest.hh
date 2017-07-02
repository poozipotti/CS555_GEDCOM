#ifndef _BIRTHBEFOREDEATHTEST_H_
#define _BIRTHBEFOREDEATHTEST_H_
#include "../include/GEDData.hh"
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

class  BirthBeforeDeathTest: public CppUnit::TestFixture {
	private:
		GEDData * testReader;
	public:
		void setUp();
		void tearDown();
		void testBirthAfterDeath();
		void testBirthBeforeDeath();
		void testNoBirthDateSpecified();
		void testNoDeathDateSpecified();
		//test to make sure that the tags are converted to
		CPPUNIT_TEST_SUITE(BirthBeforeDeathTest);
		CPPUNIT_TEST(testBirthAfterDeath);
		CPPUNIT_TEST(testBirthBeforeDeath);
		CPPUNIT_TEST(testNoBirthDateSpecified);
		CPPUNIT_TEST(testNoDeathDateSpecified);
		CPPUNIT_TEST_SUITE_END();
};


#endif
