#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkValidBirthBeforeDeath(Individual * individual){
	Date * death = individual->getDeathdate();
	if(death == NULL){
		return true;
	}
	Date * birth = individual->getBirthdate();
	if(birth == NULL){
		return true;
	}
	return ((*birth) < (*death));
}
