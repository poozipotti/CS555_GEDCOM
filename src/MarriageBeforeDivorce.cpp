#include  "../include/GEDValidityTests.hh"
//TODO this feature is not implemented yet

//returns NULL if no birthdate is specified
bool GEDValidityTests::checkMarriageBeforeDivorce(Family *  family){
    if(!family->divorced || !family->married){
        return true;
    }
    cout << "family " +to_string(family->ID) << "was divorced" << endl;
    return (*(family->divorced) > *(family->married));
}
