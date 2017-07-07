#include "../../include/GenderRoleTest.hh"
#include "../../include/GEDValidityTests.hh"

void GenderRoleTest::setUp(){
	//test bbd is a modified ged file, first person has a birth after a death, second a brith before death, thrid no brith date and fourth no deathdate
	//there is more data left in the file, there isn't any particular reason to take it out
	testReader =  new GEDData("testbbd.ged");
}
void GenderRoleTest::tearDown(){
	delete testReader;

}
void GenderRoleTest::testFamilyCorrectGenders(){
    CPPUNIT_ASSERT_MESSAGE("incorrect Family passed as correct",
    GEDValidityTests::checkFatherGender(testReader->Families[4],testReader) &&
    GEDValidityTests::checkMotherGender(testReader->Families[4],testReader));
}

void GenderRoleTest::testMotherWrongGender(){
    CPPUNIT_ASSERT_MESSAGE("incorrect Mother gender passed as correct",
    !GEDValidityTests::checkMotherGender(testReader->Families[3],testReader));
}

void GenderRoleTest::testFatherWrongGender(){
    CPPUNIT_ASSERT_MESSAGE("incorrect Father gender passed as correct",
    !GEDValidityTests::checkFatherGender(testReader->Families[3],testReader));

}
