#include "../../include/BirthBeforeDeathTest.hh"
#include "../../include/GEDValidityTests.hh"


void BirthBeforeDeathTest::setUp(){
	//test bbd is a modified ged file, first person has a birth after a death, second a brith before death, thrid no brith date and fourth no deathdate
	//there is more data left in the file, there isn't any particular reason to take it out
	testReader = new GEDData("testbbd.ged");
}
void BirthBeforeDeathTest::tearDown(){
	delete testReader;

}
void BirthBeforeDeathTest::testBirthAfterDeath(){
	CPPUNIT_ASSERT_MESSAGE("individual who had a birth after a death was not caught",!(GEDValidityTests::checkValidBirthBeforeDeath(testReader->Individuals[0])));

}
void BirthBeforeDeathTest::testBirthBeforeDeath(){
	CPPUNIT_ASSERT_MESSAGE("person with birth before death was declared incalid",(GEDValidityTests::checkValidBirthBeforeDeath(testReader->Individuals[1])));

}
void BirthBeforeDeathTest::testNoBirthDateSpecified(){
	CPPUNIT_ASSERT_MESSAGE("no birth date, should be valid",(GEDValidityTests::checkValidBirthBeforeDeath(testReader->Individuals[2])));

}
void BirthBeforeDeathTest::testNoDeathDateSpecified(){
	CPPUNIT_ASSERT_MESSAGE("no death date, should be valid",(GEDValidityTests::checkValidBirthBeforeDeath(testReader->Individuals[3])));

}
