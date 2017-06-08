#ifndef _INDIVIDUAL_
#define _INDIVIDUAL_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class GEDReader{
	private:
		vector<string> validTags;
		
	public:
		GEDReader (char* fileName);	
		void parseFile();
		vector<string> * parseLine(string);
};
#endif
