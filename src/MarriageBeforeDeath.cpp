#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkMarriageBeforeDeath(Family *  family){
    if(!family->married){
        return true;
    }
    if(!family->husbandIds.empty()&& family->husbandIds[0] && family->husbandIds[0]->deathdate && family->husbandIds[0]->deathdate < family->married ){
        return false;
    }
    if(!family->wifeIds.empty()&& family->wifeIds[0] && family->husbandIds[0]->deathdate && family->wifeIds[0]->deathdate < family->married ){
        return false;
    }
    return true;
}
