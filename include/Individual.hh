#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include "Date.hh"
#include <vector>

struct Individual{
	int ID;
	vector< vector<string> * >   tags;
    bool checkIfDead();
    Date * getBirthdate();
    Date * getDeathdate();
	string toString(){
		string outputString = "";
		outputString += to_string(ID) + ": \n{ \n";
		for(int i= 0; i<tags.size(); i++){
			outputString += "\t";
			for(int j=0; j< tags[i]->size() ; j++){
				outputString += "" + (*tags[i])[j] + " | ";
			}
			outputString += "\n";
		}
		outputString+= "}";
		return outputString;


	}
};

#endif
