#include "../include/Individual.hh"

Individual::Individual(vector < vector<string> * > _tags){
    tags = _tags;
    ID = (getIDFromTags()); name =  getNameFromTags();
    deathdate = getDeathdateFromTags();
    birthdate = getBirthdateFromTags();

}

Individual::Individual(vector<string> *  IDTag){
    tags.push_back(IDTag);
    ID = (getIDFromTags());

}
void Individual::addTag(vector<string> * tag){
        tags.push_back(tag);
}
void Individual::populateDataFromTags(){
    //cout << ("populating") << endl;
    name = getNameFromTags();
    deathdate = getDeathdateFromTags();
    birthdate = getBirthdateFromTags();
    //cout << "individual| id: " << ID << " | name: " + name << endl;
    age = -1;
    if(deathdate){
        age = Date::getYearsBetween(deathdate,birthdate);
    }else if(birthdate){
        Date * now = new Date();
        age = Date::getYearsBetween(now,birthdate);
    }
    if(age < 0){
        age = -1;
    }

}
Date * Individual::getBirthdateFromTags(){
	for(int i = 0; i<tags.size() ;i++){
		if((*tags[i])[1].substr(0,4) == "BIRT"){
			return new Date(tags[i+1]);
		}
	}
	return NULL;
}
//returns NULL if no deathdate is specified
Date * Individual::getDeathdateFromTags(){
    if(isDead()){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "DEAT"){
                return new Date(tags[i+1]);
            }
       }
    }
	return NULL;
}


bool Individual::isDead(){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "DEAT"){
                if((* tags[i])[2].substr(0,1) == "Y"){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return false;
}
bool Individual::isMale(){
        for(int i = 0; i<tags.size() ;i++){
            if((* tags[i])[1] == "SEX"){
                if((* tags[i])[2].substr(0,1) == "M"){
                    //cout <<ID << " is a male" << endl;
                    return true;
                }else{
                    //cout <<ID << " is a female" << endl;
                    return false;
                }
            }
        }
        cerr << "missing gender tag returning true as default value for individual: " << ID <<endl;
        return false;
}
int Individual::getIDFromTags(){
    vector<string> * idTag = getTag("ID");
    int i = 2;
    string ID = "";
    while((*idTag)[1][i++] != '@'){
        ID += (*idTag)[1][i-1];
    }
    return stoi(ID);
}

string Individual::getNameFromTags(){
    vector<string> * nameTag = getTag("NAME");
    if(nameTag == NULL){
         return "no name specified";
    }
    if((*nameTag)[2].find("\r") != string::npos){
         return (*nameTag)[2].substr(0,(*nameTag)[2].size()-1);
    }
    return (* nameTag)[2];
}

vector<string> * Individual::getTag(string tag){
    for(int i=0; i<tags.size();i++){
        if(tag == "ID" && (* tags[i])[1][0] == '@'){
            return (tags[i]);

        }else if((* tags[i])[1] == tag){
            //cout << "found tag " << (* tags[i])[1] <<  endl;
            return (tags[i]);
        }
    }
    return NULL;
}
