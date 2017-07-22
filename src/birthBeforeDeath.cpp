#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkValidBirthBeforeDeath(Individual * individual){
	Date * death = individual->deathdate;
	if(death == NULL){
		return true;
	}
	Date * birth = individual->birthdate;
	if(birth == NULL){
		return true;
	}
	if((*birth) < (*death)){
        return true;
    }
    cerr<< "death before birth error found in Individual " << individual->ID << endl;
    return false;
}
