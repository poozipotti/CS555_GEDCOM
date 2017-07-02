#include "../../include/isDeadTest.hh"

void IsDeadTest::setUp(){
	//test bbd is a modified ged file, first person has a birth after a death, second a brith before death, thrid no brith date and fourth no deathdate
	//there is more data left in the file, there isn't any particular reason to take it out
	testReader = new GEDData("testbbd.ged");
}
void IsDeadTest::tearDown(){
	delete testReader;

}
void IsDeadTest::testDeadIndividual(){
	CPPUNIT_ASSERT_MESSAGE("individual who is dead repoted alive",(testReader->Individuals[0]->checkIfDead()));

}
void IsDeadTest::testLivingIndividual(){
	CPPUNIT_ASSERT_MESSAGE("individual who is alive without  death tag reported dead",!(testReader->Individuals[3]->checkIfDead()));
	CPPUNIT_ASSERT_MESSAGE("individual who is alive with negative death tag reported dead",!(testReader->Individuals[4]->checkIfDead()));

}
