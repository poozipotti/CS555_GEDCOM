#include "../include/GEDReader.hh"

bool Person::checkIfDead(){
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
