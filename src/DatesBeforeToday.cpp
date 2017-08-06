#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkDateBeforeToday(Date * date){
    Date * today = new Date();
    return(*date < *today);
}
