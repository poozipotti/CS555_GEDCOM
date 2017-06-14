#include "../include/GEDReader.hh"


GEDReader::GEDReader (char* fileName){
	cout<< "tried to load " << fileName << endl;
	//doesn't actually check if arguments are vaild	
	validTags.push_back("INDI");		
	validTags.push_back("NAME");		
	validTags.push_back("SEX");		
	validTags.push_back("BIRT");		
	validTags.push_back("DEAT");		
	validTags.push_back("FAMC");		
	validTags.push_back("FAMS");		
	validTags.push_back("FAM");		
	validTags.push_back("MARR");		
	validTags.push_back("HUSB");		
	validTags.push_back("WIFE");		
	validTags.push_back("CHIL");		
	validTags.push_back("DIV");		
	validTags.push_back("DATE");		
	validTags.push_back("HEAD");		
	validTags.push_back("TRLR");		
	validTags.push_back("NOTE");		
	validTags.push_back("SURN");		
	
};

void GEDReader::parseFile (){
	string line;
	vector<string> * parsedLine;
	ifstream inputFile ("MyFamily.ged");		
	if(inputFile.is_open()){
		//this will keep track of whether the GED Reader is parsing an individual
		bool parsingIndividual = false;
		//this will keep track of whether the GED Reader is parsing a family
		bool parsingFamily = false;
		while(getline (inputFile,line)){
			parsedLine = parseLine(line);	
			//will skip lines that do not start with an ID
			if((*parsedLine)[1][0] == '@'){
				if((*parsedLine)[1][1] == 'I'){
					int i = 2;
					string ID = "";
					while((*parsedLine)[1][i++] != '@'){
						ID += (*parsedLine)[1][i-1];
					}
					parsingIndividual = true;
					parsingFamily = false;
					Individuals.push_back(new Person);
					Individuals.back()->ID =stoi(ID);
				}else if((*parsedLine)[1][1] == 'F'){
					int i = 2;
					string ID = "";
					while((*parsedLine)[1][i++] != '@'){
						ID += (*parsedLine)[1][i-1];
					}
					parsingIndividual = false;
					parsingFamily = true;
					Families.push_back(new Family);
					Families.back()->ID =stoi(ID);
				}
			}else if(parsingIndividual){
				Individuals.back()->tags.push_back(parsedLine);
			}else if(parsingFamily){
				//TODO find out what the _current tag is and implement it
				if((*parsedLine).size() >2 && (*parsedLine)[2][0] == '@'){
				    //    cout << (*parsedLine)[2]  <<endl;	
					string ID = "";
					int i = 2;
					while((*parsedLine)[2][i++] != '@'){
						ID += (*parsedLine)[2][i-1];
					}
					if((*parsedLine)[1] == "HUSB"){
						Families.back()->husbandIds.push_back(stoi(ID));
					}else if((*parsedLine)[1] == "WIFE"){
						Families.back()->wifeIds.push_back(stoi(ID));
					}else if((*parsedLine)[1] == "CHIL"){
						Families.back()->childIds.push_back(stoi(ID));
					}
				}
			}
		}
		/*
		for(int i = 0; i < Families.size(); i++){
			for(int j = 0; j<HusbanIds.size(); j++){

			}
			for(int j = 0; j<WifeIds.size(); j++){

			}
		}*/
		cout << "finished parsing lines" << endl;
	}else{
		cout << "error opening file" << endl;
	}
}
bool GEDReader::outputToFile(){
	ofstream outputFile;
	outputFile.open("Output.txt");
	for(int i =0; i<Individuals.size(); i++){
		outputFile << Individuals[i]->toString()+"\n\n";

	}
	for(int i =0; i<Families.size(); i++){
		outputFile << Families[i]->toString()+"\n\n";
	}
	outputFile.close();	
}
vector<string>  * GEDReader::parseLine(string line){
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
		//cout << output->back() << endl;
	}
	output->push_back(line);
	//cout << output->back() << endl;
	return output;
}
