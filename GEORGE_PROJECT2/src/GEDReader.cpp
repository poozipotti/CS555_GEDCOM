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
	ofstream outputFile;
	outputFile.open("Output.txt");
	if(inputFile.is_open()){
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
					Individuals.push_back(new Person);
					Individuals.back()->ID =stoi(ID);
					getline(inputFile,line);
					parsedLine = parseLine(line);
					Individuals.back()->Name = (*parsedLine)[2];
					outputFile<<" I" << Individuals.back()->ID << " | " << Individuals.back()->Name << endl;
					cout<<" I" << Individuals.back()->ID << " | " << Individuals.back()->Name << endl;
				}else if((*parsedLine)[1][1] == 'F'){
			//TODO get families working
					/*
					int i = 2;
					string ID = "";
					while((*parsedLine)[1][i++] != '@'){
						ID += (*parsedLine)[1][i-1];
					}
					
					Families.push_back(new Family);
					Families.back()->ID = stoi(ID);
					getline(inputFile,line);
					parsedLine = parseLine(line);
					ID = "";
					i=2
					while((*parsedLine)[1][i++] != '@'){
						ID += (*parsedLine)[1][i-1];
					}
					getline(inputFile,line);
					parsedLine = parseLine(line);
					Individuals.back()->Name = (*parsedLine)[2];
				*/	
					
				}
			};
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

main(){
	GEDReader AReader("MyFamily.ged");
	AReader.parseFile();
	return 0;
	
};
