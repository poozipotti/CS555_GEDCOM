#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkFatherGender(Family * family){
    if(family->husbandIds.empty()){
        return true;
    }
    for(int i=0;i<family->husbandIds.size();i++){
        if(family->husbandIds[i] == NULL){
            throw "null husband when checking gender";
        }
        if(!family->husbandIds[i]->isMale()){
            return false;
        }
    }
    return true;
}
bool GEDValidityTests::checkMotherGender(Family * family){
    if(family->wifeIds.empty()){
        return true;
    }
    for(int i=0;i<family->wifeIds.size();i++){
        if(family->wifeIds[i] == NULL){
            throw "null wife when checking gender";
        }
        if(family->wifeIds[i]->isMale()){
            return false;
        }
    }
    return true;
}
