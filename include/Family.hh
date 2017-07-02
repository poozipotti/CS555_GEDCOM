#ifndef _FAMILY_H_
#define _FAMILY_H_

#include <vector>
#include <string>
using namespace std;

struct Family{
	int ID;
	vector<int> husbandIds;
	vector<int> wifeIds;
	vector<int> childIds;
	string toString(){
		string outputString = "";

		outputString += to_string(ID) + ":\n husband Ids: \n{ \n";
		for(int i= 0; i<husbandIds.size(); i++){
			outputString += "\t";
			outputString += to_string(husbandIds[i]);
			outputString += "\n";
		}
		outputString+= "}";

		outputString += "\n wife Ids: \n{ \n";
		for(int i= 0; i<wifeIds.size(); i++){
			outputString += "\t";
			outputString += to_string(wifeIds[i]);
			outputString += "\n";
		}
		outputString+= "}";

		outputString += "\n chld Ids: \n{\n";
		for(int i= 0; i<childIds.size(); i++){
			outputString += "\t";
			outputString += to_string(childIds[i]);
			outputString += "\n";
		}
		outputString+= "}";

		return outputString;


	}
};

#endif
