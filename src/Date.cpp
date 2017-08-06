#include "../include/Date.hh"
void Date::setMonth(int _month){
	if(_month < 0 || _month > 12){
		throw  ("invalid month out of bounds!!");
	}else{
		month = _month;
	}
}
void Date::setMonth(string _month){
	int monthNum = -1;
	for(int i =0; i<NUMBER_OF_MONTHS; i++){
		if(_month == MONTHS[i]){
			monthNum = i+1;
			break;
		}
	}
	if(monthNum == -1){
		throw ( "Invalid Month Given!!");
	}else{
		month = monthNum;
	}
}
void Date::setMonthDay(int _day){
	if(_day < 0 || _day > 31){
		throw  "invalid day out of bounds!!";
	}else{
		monthDay = _day;
	}
}
void Date::setYear(int _year){
	if(_year < 0){
		throw  "is invalid year out of bounds!!";
	}else{
		year = _year;
	}
}

Date::Date(vector<string> * tag){
	setFromTag(tag);
};

Date::Date(int _month, int _day, int _year){
	setMonth(_month);
	setMonthDay(_day);
	setYear(_year);
    timeStruct = new tm;
    timeStruct->tm_year = year -1900;
    timeStruct->tm_mon = month;
    timeStruct->tm_mday = monthDay;

};

Date::Date(string _month, int _day, int _year){
	setMonth(_month);
	setMonthDay(_day);
	setYear(_year);
    timeStruct = new tm;
    timeStruct->tm_year = _year -1900;
    timeStruct->tm_mon = month;
    timeStruct->tm_mday = monthDay;
};
Date::Date(time_t time){
    timeStruct = localtime(&time);
	setMonth(timeStruct->tm_mon);
	setMonthDay(timeStruct->tm_mday);
	setYear(timeStruct->tm_year + 1900);

}
double Date::getDaysBetween(Date * dateOne, Date * dateTwo){
    time_t dateOneSecs = mktime(dateOne->timeStruct);
    time_t dateTwoSecs = mktime(dateTwo->timeStruct);
    return floor(difftime(dateOneSecs,dateTwoSecs) / (60* 60*24));
}
double Date::getYearsBetween(Date* dateOne,Date* dateTwo ){
    return floor(getDaysBetween(dateOne,dateTwo)/365);
}
void Date::setFromTag(vector<string> * tag){
	if((* tag)[1] != "DATE"){
		throw "must be given a DATE tag!";
	}
	string dateString = (*tag)[2];
	setMonthDay(stoi(dateString.substr(0,dateString.find(' '))));
	dateString = dateString.substr(dateString.find(" ")+1,dateString.size()-1);
	setMonth(dateString.substr(0,dateString.find(" ")));
	dateString = dateString.substr(dateString.find(" ")+1,dateString.size()-1);
	setYear(stoi(dateString.substr(0,dateString.find(" "))));
}

