#ifndef _FAMILY_H_
#define _FAMILY_H_

#include <vector>
#include <string>
#include "Individual.hh"
using namespace std;

struct Family{
	int ID;
    bool current;
	vector<Individual *> husbandIds;
	vector<Individual *> wifeIds;
	vector<Individual *> childIds;
    //TODO implement
	string toString(){
        string outputString = "";
		return outputString;
	}
};

#endif
