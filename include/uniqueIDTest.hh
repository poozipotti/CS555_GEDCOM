#ifndef _UNIQUEIDTEST_H_
#define _UNIQUEIDTEST_H_
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

class  UniqueIDTest: public CppUnit::TestFixture {
	private:
		GEDData * testReaderValidGED;
        GEDData * testReaderInvalidGED;
	public:
		void setUp();
		void tearDown();
		void testAllUniqueIds();
		void testIndividualNonUniqueIds();
		void testFamilyNonUniqueIds();
		//test to make sure that the tags are converted to
		CPPUNIT_TEST_SUITE(UniqueIDTest);
		CPPUNIT_TEST(testAllUniqueIds);
		CPPUNIT_TEST(testIndividualNonUniqueIds);
		CPPUNIT_TEST(testFamilyNonUniqueIds);
		CPPUNIT_TEST_SUITE_END();
};


#endif
