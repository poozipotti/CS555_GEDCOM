#include "../../include/GEDReader.hh" 

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

class GEDReaderTest : public CppUnit::TestFixture {
	private:
	  GEDReader *AReader;
	public:
	  void setUp()
	  {
		AReader = new GEDReader("myFamily.ged");	
	  }
	

	  void tearDown() 
	  {
	    delete AReader;
	  }
	  void testValidBirthAndDeath(){
		CPPUNIT_ASSERT(AReader->checkValidBirthBeforeDeath(new Person()));
	  }
	  void testInvalidBirthAndDeath(){
		CPPUNIT_ASSERT(!AReader->checkValidBirthBeforeDeath(new Person()));
	  }
	  CPPUNIT_TEST_SUITE(GEDReaderTest);
	  CPPUNIT_TEST(testValidBirthAndDeath);
	  CPPUNIT_TEST(testInvalidBirthAndDeath);
	  CPPUNIT_TEST_SUITE_END();
};
main(){
	cout<< "starting tests" << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(GEDReaderTest::suite());	
	runner.run();
	return 0;
}

