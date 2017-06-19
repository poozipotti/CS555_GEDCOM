#include  "../include/GEDReader.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified 
Date * getBirthdate(Person * person){
	for(int i = 0; i<person->tags.size() ;i++){
		if((*person->tags[i])[1].substr(0,4) == "BIRT"){
			return new Date(person->tags[i+1]);	
		}
	}	
	return NULL;
}
//returns NULL if no deathdate is specified
Date * getDeathdate(Person * person){
	for(int i = 0; i<person->tags.size() ;i++){
		if((*person->tags[i])[1] == "DEAT"){
			return new Date(person->tags[i+1]);	
		}
	}	
	return NULL;
}

bool GEDReader::checkValidBirthBeforeDeath(Person * person){
	Date * death = getDeathdate(person);
	if(death == NULL){
		return true;
	}
	Date * birth = getBirthdate(person);
	if(birth == NULL){
		return true;
	}
	return ((*birth) < (*death));
}
