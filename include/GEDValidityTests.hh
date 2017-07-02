#ifndef _GEDVALIDITYTESTER_H_
#define _GEDVALIDITYTESTER_H_
//TODO include all of the different ways to check if
//a GED is valid or not
// Tests are valid methods and take in individuals or families
#include "Individual.hh"
#include "Family.hh"
#include "Date.hh"

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
};
#endif
