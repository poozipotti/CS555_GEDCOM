#include "../include/GEDData.hh"


GEDData::GEDData (char* _fileName){
	fileName = _fileName;
	//doesn't actually check if arguments are vaild
	parseFile();

};

vector<string>  * GEDData::parseLine(string line){
	int maxTokens = 3;
	vector<string> * output = new vector<string>;
	//cout << line << endl;
	for (int i = 0; i < maxTokens-1; i++){
		if(line.find(' ') == -1){
			output->push_back(line);
			//cout<< " line ended early" << endl;
			return output;
		}
		output->push_back(line.substr(0, line.find(' ')));
		line = line.substr(line.find(' ')+1, line.size()-1 );
		//cout << ou,tput->back() << endl;
	}
	output->push_back(line);
	//cout << output->back() << endl;
	return output;
}

void GEDData::parseFile (){
	string line;
	vector<string> * parsedLine;
	ifstream inputFile (fileName);
	if(inputFile.is_open()){
		//this will keep track of whether the GED Reader is parsing an individual
		bool parsingIndividual = false;
		//this will keep track of whether the GED Reader is parsing a family
		bool parsingFamily = false;
        int tempID;
		while(getline (inputFile,line)){
			parsedLine = parseLine(line);
			//will skip lines that do not start with an ID
			if((*parsedLine)[1][0] == '@'){
				if((*parsedLine)[1][1] == 'I'){
                    addNewIndividual(parsedLine);
                    tempID = Individuals.back()->ID;
					parsingIndividual = true;
					parsingFamily = false;
				}else if((*parsedLine)[1][1] == 'F'){
					int i = 2;
					string ID = "";
					while((*parsedLine)[1][i++] != '@'){
						ID += (*parsedLine)[1][i-1];
					}
                    tempID = stoi(ID);
					parsingIndividual = false;
					parsingFamily = true;
                    addNewFamily(tempID);
				}
			}else if(parsingIndividual){
                addTagToIndividual(tempID,parsedLine);
			}else if(parsingFamily){
                addMemberToFamily(tempID,parsedLine);

            }else{
                addTagToOpening(parsedLine);
            }
		}
        for(int i=0; i<Individuals.size();i++){
            Individuals[i]->populateDataFromTags();
           cout<< Individuals[i] ->toString() << endl;
        }
		cout << "finished parsing lines" << endl;
	}else{
		cout << "error opening file" << endl;
	}
}
void GEDData::addNewIndividual(vector<string> * IDtag){
    Individuals.push_back(new Individual(IDtag));

}
void GEDData::addNewFamily(int ID){
    Families.push_back(new Family);
    Families.back()->ID = ID;

}
void GEDData::addTagToOpening(vector<string> * tag){
    openingTags.push_back(tag);
}
void GEDData::addTagToIndividual(int ID, vector<string> * tag){
    for(int i =0; i<Individuals.size(); i++){
        if(Individuals[i]->ID == ID ){
            Individuals[i]->addTag(tag);
        }
    }

    //throw("Individual was not found in individual list");
}
//TODO reflect that addMemberToFamily also sets _CRURRET tag
void GEDData::addMemberToFamily(int ID, vector<string> * tag){
    for(int i =0; i<Families.size(); i++){
        if(Families[i]->ID == ID ){
            if((*tag).size() >2){
                if((*tag)[2][0] == '@'){
                    string ID = "";
                    int j = 2;
                    while((*tag)[2][j++] != '@'){
                        ID += (*tag)[2][j-1];
                    }
                    if((*tag)[1] == "HUSB"){
                        Families[i]->husbandIds.push_back(stoi(ID));
                    }else if((*tag)[1] == "WIFE"){
                        Families[i]->wifeIds.push_back(stoi(ID));
                    }else if((*tag)[1] == "CHIL"){
                        Families[i]->childIds.push_back(stoi(ID));
                    }
                }else if((*tag)[1] == "_CURRENT" ){
                    Families[i]->current = ((*tag)[2] == "Y");
                }
            }
        }
    }
}

