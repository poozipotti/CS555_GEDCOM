#include  "../include/GEDValidityTests.hh"

vector< vector<int> *  > GEDValidityTests::checkValidUniqueID(GEDData * data){
    //TODO check if this is a memory leak
    //TODO id's will get added the amount of times they are repeated, this is kind of wasteful and could be fixed but it really doesn't matter for the moment
    vector< vector<int> *> output;
    output.push_back(new vector<int>);
    output.push_back(new vector<int>);
    for(int i=0; i< data->Individuals.size()-1; i++){
        for(int j=i+1; j< data->Individuals.size(); j++){
            if(data->Individuals[i]->ID == data->Individuals[j]->ID ){
                (* output[0]).push_back(data->Individuals[i]->ID);
                break;
            }
        }
    }
    for(int i=0; i< data->Families.size()-1; i++){
        for(int j=i+1; j< data->Families.size(); j++){
            if(data->Families[i]->ID == data->Families[j]->ID ){
                (* output[1]).push_back(data->Families[i]->ID);
                break;
            }
        }
    }
    return output;
}
