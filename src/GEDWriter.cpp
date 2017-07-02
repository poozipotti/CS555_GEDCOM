#include "../include/GEDWriter.hh"

GEDWriter::GEDWriter(GEDData * _data){
    data = _data;
}

bool GEDWriter::writeNewFile(char* fileName, bool Test){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));

	for(int i =0; i< data->openingTags.size(); i++){
        outputFile<<tagToString(data->openingTags[i])<<endl;
    }
	for(int i =0; i < data->Individuals.size(); i++){
        outputFile<<checkIndividual(data->Individuals[i]);
	}
	for(int i =0; i<data->Families.size(); i++){
        //TODO familes to things
	}
    outputFile << "TRLR" << endl;
	outputFile.close();
}
bool GEDWriter::listTheDead(char* fileName){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));

	for(int i =0; i< data->openingTags.size(); i++){
        outputFile<<tagToString(data->openingTags[i])<<endl;
    }
	for(int i =0; i < data->Individuals.size(); i++){
        if(data->Individuals[i]->checkIfDead()){
            outputFile << checkIndividual(data->Individuals[i]);
        }
	}
	for(int i =0; i<data->Families.size(); i++){
        //TODO familes to things
	}
    outputFile << "TRLR" << endl;
	outputFile.close();

}
string GEDWriter::tagToString(vector<string> * tag){
    string output = "";
    for(int i =0; i<(*tag).size(); i++){
        output += (*tag)[i];
        //TODO don't add a space on the very end
        output += " ";
    }
    return output;
}


string GEDWriter::checkIndividual(Individual * individual){
    string output= "" ;
    output +=  "@"+ to_string(individual->ID)+"@ INDI\n";
    if(!GEDValidityTests::checkValidBirthBeforeDeath(individual)){
        output += "1 NOTE |||||||||||||||||CHECK RECORD DEATH IS BEFORE BIRTH||||||||||||||\n";
    }
    for(int j= 0; j< individual->tags.size(); j++){

       output+= tagToString(individual->tags[j])+'\n';
    }
    return output;
}
