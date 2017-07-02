#ifndef _ISDEADTEST_H_
#define _ISDEADTEST_H_
#include "GEDData.hh"
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

class  IsDeadTest: public CppUnit::TestFixture {
	private:
		GEDData * testReader;
	public:
		void setUp();
		void tearDown();
		void testDeadIndividual();
		void testLivingIndividual();
		//test to make sure that the tags are converted to
		CPPUNIT_TEST_SUITE(IsDeadTest);
		CPPUNIT_TEST(testDeadIndividual);
		CPPUNIT_TEST(testLivingIndividual);
		CPPUNIT_TEST_SUITE_END();
};


#endif
