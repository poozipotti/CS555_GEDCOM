#ifndef _GEDREADER_H_
#define _GEDREADER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//this struct will hold an indviduals data, or a husband or wive's
struct Person{
	int ID;
	string Name;
};
struct Family{
	int ID;
	vector<int> husbandIds;
	vector<int> wifeIds;
};

class GEDReader{
	private:
		vector<string> validTags;
		//vector of all the individuals in a family
		vector<Person * > Individuals;
		//vector<Family *> Families;
		
	public:
		GEDReader (char* fileName);	
		void parseFile();
		vector<string> * parseLine(string);
};
#endif

