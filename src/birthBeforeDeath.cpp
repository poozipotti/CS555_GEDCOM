#include  "../include/GEDReader.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
Date * Person::getBirthdate(){
	for(int i = 0; i<tags.size() ;i++){
		if((*tags[i])[1].substr(0,4) == "BIRT"){
			return new Date(tags[i+1]);
		}
	}
	return NULL;
}
//returns NULL if no deathdate is specified
Date * Person::getDeathdate(){
    if(checkIfDead()){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "DEAT"){
                return new Date(tags[i+1]);
            }
        }
    }
	return NULL;
}

bool GEDReader::checkValidBirthBeforeDeath(Person * person){
	Date * death = person->getDeathdate();
	if(death == NULL){
		return true;
	}
	Date * birth = person->getBirthdate();
	if(birth == NULL){
		return true;
	}
	return ((*birth) < (*death));
}
