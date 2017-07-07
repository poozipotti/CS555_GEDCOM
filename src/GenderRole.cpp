#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkFatherGender(Family * family, GEDData * data){
    if(family->husbandIds.empty()){
        return true;
    }
    for(int i=0;i<data->Individuals.size();i++){
        if(data->Individuals[i]->ID == family->husbandIds[0]){
            return(data->Individuals[i]->isMale());
        }
    }
    throw "could not find husband in individuals";
}
bool GEDValidityTests::checkMotherGender(Family * family, GEDData * data){
    if(family->wifeIds.empty()){
        return true;
    }
    for(int i=0;i<data->Individuals.size();i++){
        if(data->Individuals[i]->ID == family->wifeIds[0]){
            return(!data->Individuals[i]->isMale());
        }
    }
    throw "could not find husband in individuals";
}
