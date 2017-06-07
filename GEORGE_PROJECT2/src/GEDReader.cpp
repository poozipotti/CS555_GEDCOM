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
			outputFile<<line<<"\n";
			parsedLine = parseLine(line);	
		
			for(int i = 0; i < parsedLine->size(); i++){
				outputFile << (*parsedLine)[i];
				if(i == 1){
					bool valid = false;
					for(int j = 0; j < validTags.size(); j++){
						if(((*parsedLine)[i] ==  validTags[j])){
							cout << "valid tag: |" << (*parsedLine)[i] << "|" << endl;
							valid = true;
							outputFile << "|Y";
						}else{
						//	cout << "tag doesn't match: " << (*parsedLine)[i] << " " <<  validTags[j] <<  endl;
						}
					}
						
						
						
					if(!valid){
						cout<< "invalid tag: |" << (*parsedLine)[i] << "|" << endl;
						outputFile << "|N";
					}
						
				}
				outputFile << "|";
			}
			outputFile<< '\n' ;	
		}
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
			cout<< " line ended early" << endl;
			break;	
		}
		output->push_back(line.substr(0, line.find(' ')));
		line = line.substr(line.find(' ')+1, line.size()-1 );
		cout << output->back() << endl;
	}
	output->push_back(line);
	cout << output->back() << endl;
	return output;
}

main(){
	GEDReader AReader("MyFamily.ged");
	AReader.parseFile();
	return 0;
	
};
