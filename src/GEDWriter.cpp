#include "../include/GEDWriter.hh"

GEDWriter::GEDWriter(GEDData * _data){
    data = _data;
}

bool GEDWriter::writeNewGEDFile(char* fileName, bool Test){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));

	for(int i =0; i< data->openingTags.size(); i++){
        outputFile<<tagToString(data->openingTags[i])<<endl;
    }
	for(int i =0; i < data->Individuals.size(); i++){
        outputFile<<getCheckedIndividualGED(data->Individuals[i]);
	}
	for(int i =0; i<data->Families.size(); i++){
        outputFile<<getCheckedFamilyGED(data->Families[i]);
	}
    outputFile << "TRLR" << endl;
	outputFile.close();
}
bool GEDWriter::writeOutputFile(char* fileName, bool Test){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));
    vector< vector<string> * > individualStrings;
	for(int i =0; i < data->Individuals.size(); i++){
        vector<string> * temp = new vector<string>();
        temp->push_back((to_string(data->Individuals[i]->ID)));
        temp->push_back(data->Individuals[i]->name);
        individualStrings.push_back(temp);
	}
    vector<string> columnHeadings = {"id","name","gender","birthday","age","alive","death","child","spouse"};
    outputFile << formatToTable(individualStrings,columnHeadings,20);
	outputFile.close();
}
string GEDWriter::formatToTable(vector< vector<string> *> individualStrings,vector<string> columnHeadings, int columnSize){
    string outputString = "";
    for(int i=0;i<columnHeadings.size()*columnSize + columnHeadings.size()/2 + 2;i++){
        outputString += "-";
    }
    outputString += "\n";
    outputString += "|";
    for(int i=0; i<columnHeadings.size(); i++){
        //not optimied formatted for readability
        //TODO this assumes the solumn size is bigger than the headings
        int offset = (columnSize - columnHeadings[i].size()) /2;
        for(int j=0;j<offset;j++){
            outputString += " ";
        }
        outputString+= columnHeadings[i];
        for(int j=0;j<offset;j++){
            outputString += " ";
        }
        outputString += "|";
    }
    outputString += "\n";
    for(int i=0;i<columnHeadings.size()*columnSize + columnHeadings.size()/2 + 2;i++){
        outputString += "-";
    }
    return outputString;
}

bool GEDWriter::listTheDead(char* fileName){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));

	for(int i =0; i< data->openingTags.size(); i++){
        outputFile<<tagToString(data->openingTags[i])<<endl;
    }
	for(int i =0; i < data->Individuals.size(); i++){
        if(data->Individuals[i]->isDead()){
            outputFile << getCheckedIndividualGED(data->Individuals[i]);
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


string GEDWriter::getCheckedIndividualGED(Individual * individual){
    vector< vector<int> * > nonUniqueIDS = GEDValidityTests::checkValidUniqueID(data);
    bool uniqueID = true;
    string output= "" ;
    for(int i =0; i< (* nonUniqueIDS[0]).size(); i++){
        if(individual->ID == (* nonUniqueIDS[0])[i]){
            uniqueID = false;
            break;
        }
    }
    if(!uniqueID){
        output += "1 NOTE |||||||||||||||||INDIVIDUAL DOES NOT HAVE UNIQUE ID||||||||||||||\n";
    }
    if(!GEDValidityTests::checkValidBirthBeforeDeath(individual)){
        output += "1 NOTE |||||||||||||||||CHECK RECORD DEATH IS BEFORE BIRTH||||||||||||||\n";
    }
    for(int j= 0; j< individual->tags.size(); j++){

       output+= tagToString(individual->tags[j])+'\n';
    }
    return output;
}
string GEDWriter::getCheckedFamilyGED(Family * family){
    vector< vector<int> * > nonUniqueIDS = GEDValidityTests::checkValidUniqueID(data);
    bool uniqueID = true;
    string output= "" ;
    output +=  "@F"+ to_string(family->ID)+"@ FAM\n";
    for(int i =0; i< (* nonUniqueIDS[1]).size(); i++){
        if(family->ID == (* nonUniqueIDS[1])[i]){
            uniqueID = false;
            break;
        }
    }
    if(!uniqueID){
        output += "1 NOTE |||||||||||||||||Family DOES NOT HAVE UNIQUE ID||||||||||||||\n";
    }
    try{
        if(!GEDValidityTests::checkFatherGender(family , data)){
            output += "1 NOTE |||||||||||||||||FATHER IS LISTED AS FEMALE||||||||||||||\n";
        }
        if(!GEDValidityTests::checkMotherGender(family , data)){
            output += "1 NOTE |||||||||||||||||MOTHER IS LISTED AS MALE||||||||||||||\n";

        }
    }catch(char const* error){
        cerr << "there was an error in finding a husband or wife when trying to check their gender, check for duplicate ids" << endl;
    }

    for(int j= 0; j< family->husbandIds.size(); j++){
       output+= "HUSB @I" + to_string(family->husbandIds[j])+"@\n";
    }
    for(int j= 0; j< family->wifeIds.size(); j++){
       output+= "WIFE @I" + to_string(family->wifeIds[j])+"@\n";
    }
    for(int j= 0; j< family->childIds.size(); j++){
       output+= "CHIL @I" + to_string(family->childIds[j])+"@\n";
    }
    return output;

}
