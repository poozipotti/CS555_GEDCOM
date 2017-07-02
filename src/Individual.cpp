#include "../include/Individual.hh"

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


bool Individual::checkIfDead(){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "DEAT"){
                if((* tags[i])[2].substr(0,1) == "Y"){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return false;
}
