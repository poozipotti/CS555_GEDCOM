#ifndef _GEDDATA_H_
#define _GEDDATA_H_

#include <iostream>
#include <fstream>
#include "Date.hh"
#include "Individual.hh"
#include "Family.hh"

using namespace std;

class GEDData{
        private:
            char * fileName;
            //parses a line and tokenizes it into a vector to be processed easily
            vector<string> * parseLine(string);
            //TODO find a new home for this method
            //coneverts a tag into a Date object
            Date * convertToDate(vector<string> tag);
        public:
            vector<Family *> Families;
            vector<Individual * > Individuals;
            GEDData (char* _fileName);
            //parses an entire GED file and stores it's data
            void parseFile();
            void addNewIndividual(vector<string> *);
            void addNewFamily(int ID);
            void addTagToOpening(vector<string> * tag);
            void addTagToIndividual(int ID, vector<string> * tag);
            void addMemberToFamily(int ID, vector<string> * tag);
            void addMarriageToFamily(int ID, vector<string> * tag);
            void addDivorceToFamily(int ID, vector<string> * tag);
            Individual * getIndividualByID(int);
            //this is data that is before the first indiividual
            //TODO eventually make this data more granular
            vector<vector<string> *> openingTags;
};

#endif

