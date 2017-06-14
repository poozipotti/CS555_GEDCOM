#ifndef _GEDREADER_H_
#define _GEDREADER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//1this struct will hold an indviduals data, or a husband or wive's
struct Person{
	int ID;
	vector< vector<string> * >   tags;		
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

class GEDReader{
	private:
		vector<string> validTags;
		//vector of all the individuals in a family
		vector<Person * > Individuals;
		vector<Family *> Families;
		bool checkValidBirthBeforeDeath(Person *);		
	public:
		GEDReader (char* fileName);	
		bool outputToFile();
		void parseFile();
		vector<string> * parseLine(string);
};
#endif

