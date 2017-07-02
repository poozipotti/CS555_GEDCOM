#ifndef _GEDWRITER_H_
#define _GEDWRITER_H_

//TODO the writer writes a new GED file that is similiar to the old one
//includes notes to show which individuals or families are invalid

//TODO give the writer different options like -v for a verbose option or -s for a
//silent option. (i'm not sure if -s is for silent i want to check on the unix junk)
#include "GEDData.hh"

using namespace std;

class GEDWriter{
    private:
        GEDData * data;
        //remember to add all of the tests from GEDVAilidityTester into the check individuals and check families
        //if new ones are added
        void checkIndividual();
        void checkFamily();
        string tagToString(vector<string> * tag);
    public:
        GEDWriter(GEDData * _data);
        bool writeNewFile(char* fileName, bool test);

};

#endif

