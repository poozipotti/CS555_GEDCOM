#ifndef _GEDVALIDITYTESTER_H_
#define _GEDVALIDITYTESTER_H_
//TODO include all of the different ways to check if
//a GED is valid or not
// Tests are valid methods and take in individuals or families
#include "Individual.hh"
#include "Family.hh"
#include "Date.hh"
#include "GEDData.hh"

namespace GEDValidityTests{
    //TODO check if this is bad form (to declare a variable in a namespace)
    const string validTagsp[] =
    {
        "INDI","NAME", "SEX","BIRT","DEAT","FAMC","FAMS","FAM",
        "MARR","HUSB","WIFE","CHIL","DIV","DATE","HEAD","TRLR","NOTE",
        "SURN"
    };
    //remember to add all of the tests from GEDVAilidityTester into the check individuals and check families
    //if new ones are added
    bool checkValidBirthBeforeDeath(Individual *);
    //outputs 2 dimensional vector of ids that are not unique, a list of individual id's at [0] and  family id's at [1]
    vector< vector<int> *> checkValidUniqueID(GEDData *);
    bool checkFatherGender(Family *);
    bool checkMotherGender(Family *);
    bool checkDateBeforeToday(Date *);
    bool checkTooOld(Individual *);
    bool checkMarriageBeforeDivorce(Family * );
    bool checkMarriageBeforeDeath(Family * );
};
#endif
