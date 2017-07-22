#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include "Date.hh"
#include <vector>

struct Individual{
    int ID;
    string name;
    vector< vector<string> * >   tags;
    Date * deathdate;
    Date * birthdate;
    vector<int> * childIds;
    vector<int> * spouseIds;

    Individual(vector < vector<string> * > _tags);
    Individual(vector<string> *  _tags);
    bool isDead();
    bool isMale();
    string getNameFromTags();
    int getIDFromTags();
    Date * getBirthdateFromTags();
    Date * getDeathdateFromTags();
    vector<int> * getChildIds;
    vector<int> * getSpouseIds;
    void populateDataFromTags();
    void addTag(vector<string> * );

    //TODO this is obsolete
    string toString(){
        string outputString = "";
        outputString += to_string(ID) + ": \n{ \n";
        outputString += "\t " + name + "\n";
        outputString+= "}";
        return outputString;
    }
    private:
    vector<string> * getTag(string tag);

};

#endif
