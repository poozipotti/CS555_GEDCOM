#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkTooOld(Individual * individual){
    int cutOffAge = 150;
    if(individual->age > cutOffAge){
        return false;
    }else{
        return true;
    }
}
