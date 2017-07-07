#ifndef _GENDERROLETEST_H_
#define _GENDERROLETEST_H_
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

class  GenderRoleTest: public CppUnit::TestFixture {
	private:
		GEDData * testReader;
	public:
		void setUp();
		void tearDown();
        void testFamilyCorrectGenders();
		void testMotherWrongGender();
		void testFatherWrongGender();
		//test to make sure that the tags are converted to
		CPPUNIT_TEST_SUITE(GenderRoleTest);
		CPPUNIT_TEST(testFamilyCorrectGenders);
		CPPUNIT_TEST(testMotherWrongGender);
		CPPUNIT_TEST(testFatherWrongGender);
		CPPUNIT_TEST_SUITE_END();
};


#endif
