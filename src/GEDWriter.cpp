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
        //TODO reimplement if this feature is needed in the future
        //outputFile<<getCheckedFamilyGED(data->Families[i]);
	}
    outputFile << "TRLR" << endl;
	outputFile.close();
}
bool GEDWriter::writeOutputFile(char* fileName, bool Test){
    //TODO make it return a bool
    ofstream outputFile;
	outputFile.open(string(fileName));
    Date * today = new Date();
    outputFile << "Output created on:" + (today->toString()) << endl;
    vector< vector<string> * > individualStrings;
    /////////Individuals/////////////////////////////////////////////////
	for(int i =0; i < data->Individuals.size(); i++){
        vector<string> * temp = new vector<string>();
        temp->push_back((to_string(data->Individuals[i]->ID)));
        temp->push_back(data->Individuals[i]->name);
        if(data->Individuals[i]->isMale()){
            temp->push_back("male");
        }else{
            temp->push_back("female");
        }
        if(data->Individuals[i]->birthdate != NULL){
        temp->push_back(data->Individuals[i]->birthdate->toString());
        }else{
            temp->push_back("n/a");
        }
        temp->push_back("not implemented");
        if(data->Individuals[i]->isDead()){
            temp->push_back("False");
            if(data->Individuals[i]->deathdate != NULL){
                temp->push_back(data->Individuals[i]->deathdate->toString());
            }else{
                temp->push_back("n/a");
            }
        }else{
            temp->push_back("True");
            temp->push_back("n/a");
        }
        temp->push_back("not implemented");
        temp->push_back("not implemented");
        individualStrings.push_back(temp);
	}
    vector<string> columnHeadings = {"id","name","gender","birthday","age","alive","death","child","spouse"};
    outputFile << formatToTable(individualStrings,columnHeadings,28);
    outputFile << "\n\n///////////////////////INDIVIDUAL ERRORS//////////////////////////\n\n" ;
    outputFile << getIndividualErrors();
    ///////////////////Families//////////////////////////////////////////////////////////////

    vector<vector<string> * > familyStrings;
	for(int i =0; i < data->Families.size(); i++){
        vector<string> * temp = new vector<string>();
        temp->push_back((to_string(data->Families[i]->ID)));
        temp->push_back("not implemented");
        temp->push_back("not implemented");
        if(data->Families[i]->husbandIds.empty() || data->Families[i]->husbandIds[0] == NULL){
            temp->push_back("n/a");
            temp->push_back("n/a");
        }else{
            temp->push_back( "@" + to_string(data->Families[i]->husbandIds[0]->ID) + "@");
            temp->push_back( data->Families[i]->husbandIds[0]->name);
        }
        if(data->Families[i]->wifeIds.empty() || data->Families[i]->wifeIds[0] == NULL){
            temp->push_back("n/a");
            temp->push_back("n/a");
        }else{
            temp->push_back("@"+ to_string(data->Families[i]->wifeIds[0]->ID) + "@");
            temp->push_back( data->Families[i]->wifeIds[0]->name);
        }
        string tempString = "{";
        for(int j=0;j< data->Families[i]->childIds.size();j++){
            if(j!= 0){
                tempString += ",";
            }
            if(data->Families[i]->childIds[j] == NULL){
                tempString += "error" ;
            }else{
                tempString += "@";
                tempString += to_string(data->Families[i]->childIds[j]->ID);
                tempString += "@";
            }
        }
        tempString+="}";
        temp->push_back(tempString);
        familyStrings.push_back(temp);
	}
    vector<string> familyColumnHeadings = {"id","Married","Divorced","HusbandId","Husband Name","WifeId","Wife Name","children"};
    outputFile << "\n\n" <<endl;
    outputFile << formatToTable(familyStrings,familyColumnHeadings,28);
    outputFile << "\n\n///////////////////////Family ERRORS//////////////////////////\n\n" ;
    outputFile << getFamilyErrors();

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
        if(columnHeadings[i].size() %2 != 0){
            offset++;
        }
        for(int j=0;j<offset;j++){
            outputString += " ";
        }
        outputString += "|";
    }
    outputString += "\n";
    for(int i=0;i<columnHeadings.size()*columnSize + columnHeadings.size()/2 + 2;i++){
        outputString += "-";
    }
    outputString += "\n";
    for(int i= 0; i<individualStrings.size(); i++){
        outputString += "|";
        for(int j=0; j<columnHeadings.size();j++){
            int offset =0;
            if(j<(individualStrings[i]->size())){
                offset = (columnSize - (*individualStrings[i])[j].size()) /2;

                for(int h=0;h<offset;h++){
                    outputString += " ";
                }
                outputString+= (*individualStrings[i])[j];
                if((*individualStrings[i])[j].size() %2 != 0){
                    offset++;
                }
            }else{
                offset = columnSize;
            }
            for(int h=0;h<offset;h++){
                outputString += " ";
            }
            outputString += "|";

        }
        outputString += "\n";
        for(int h=0;h<columnHeadings.size()*columnSize + columnHeadings.size()/2 + 2;h++){
            outputString += "-";
        }
        outputString += "\n";
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

string GEDWriter::getIndividualErrors(){
    string output;
    vector< vector<int> * > nonUniqueIDS = GEDValidityTests::checkValidUniqueID(data);
    for(int i=0;i<data->Individuals.size(); i++){
        for(int j =0; j< (* nonUniqueIDS[0]).size(); j++){
            if(data->Individuals[i]->ID == (* nonUniqueIDS[0])[j]){
                output += "ERROR individual @" + to_string(data->Individuals[i]->ID) +"@ with name " + data->Individuals[i]->name + " does not have a unique ID\n";
                break;
            }
        }
        if(!GEDValidityTests::checkValidBirthBeforeDeath(data->Individuals[i])){
                output += "ERROR individual @" + to_string(data->Individuals[i]->ID) +"@ with name " + data->Individuals[i]->name + "died before they were born\n";
        }
        if(data->Individuals[i]->birthdate && !GEDValidityTests::checkDateBeforeToday(data->Individuals[i]->birthdate)){
                output += "ERROR individual @" + to_string(data->Individuals[i]->ID) +"@ with name " + data->Individuals[i]->name + "was born in the future\n";
        }

        if(data->Individuals[i]->deathdate && !GEDValidityTests::checkDateBeforeToday(data->Individuals[i]->deathdate)){
                output += "ERROR individual @" + to_string(data->Individuals[i]->ID) +"@ with name " + data->Individuals[i]->name + "died in the future\n";
        }



    }
    return output;
}
string GEDWriter::getFamilyErrors(){
    string output;
    vector< vector<int> * > nonUniqueIDS = GEDValidityTests::checkValidUniqueID(data);
    for(int i=0;i<data->Families.size(); i++){
        for(int j =0; j< (* nonUniqueIDS[1]).size(); j++){
            if(data->Families[i]->ID == (* nonUniqueIDS[1])[j]){
                output += "ERROR Family @" + to_string(data->Families[i]->ID) +"@ does not have a unique ID\n";
                break;
            }
        }
        try{
            if(!GEDValidityTests::checkFatherGender(data->Families[i])){
                output += "ERROR Familiy @" + to_string(data->Families[i]->ID) +"@ FATHER IS LISTED AS FEMALE \n";
            }
            if(!GEDValidityTests::checkMotherGender(data->Families[i])){
                output += "ERROR Familiy @" + to_string(data->Families[i]->ID) +"@ MOTHER IS LISTED AS MALE \n";

            }
        }catch(char const* error){
            cerr << "there was an error in finding a husband or wife when trying to check their gender, check for duplicate ids" << endl;
        }


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
    //TODO re implement if feature is needed in the future
    /*
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
    */
}
