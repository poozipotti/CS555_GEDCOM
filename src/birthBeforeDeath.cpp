#include  "../include/GEDReader.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
Date * Individual::getBirthdate(){
	for(int i = 0; i<tags.size() ;i++){
		if((*tags[i])[1].substr(0,4) == "BIRT"){
			return new Date(tags[i+1]);
		}
	}
	return NULL;
}
//returns NULL if no deathdate is specified
Date * Individual::getDeathdate(){
    if(checkIfDead()){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "DEAT"){
                return new Date(tags[i+1]);
            }
        }
    }
	return NULL;
}

bool GEDReader::checkValidBirthBeforeDeath(Individual * individual){
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
