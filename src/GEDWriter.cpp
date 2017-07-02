#include "../include/GEDWriter.hh"

GEDWriter::GEDWriter(GEDData * _data){
    data = _data;
}

bool GEDWriter::writeNewFile(char* fileName = "GED_OUTPUT", bool Test=true){
    ofstream outputFile;
	outputFile.open(string(fileName) + "_Output.txt");
	for(int i =0; i< data->Individuals.size(); i++){
		outputFile << data->Individuals[i]->toString()+"\n\n";

	}
	for(int i =0; i<data->Families.size(); i++){
		outputFile << data->Families[i]->toString()+"\n\n";
	}
	outputFile.close();
}
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
