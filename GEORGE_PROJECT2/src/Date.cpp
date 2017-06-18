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
		cerr << _day <<  " is invalid day out of bounds!!" << endl;
	}else{	
		monthDay = _day;
	}
}
void Date::setYear(int _year){
	if(_year < 0){
		cerr << _year<<  " is invalid year out of bounds!!" << endl;
		return;
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
};

Date::Date(string _month, int _day, int _year){
	setMonth(_month);
	setMonthDay(_day);
	setYear(_year);	
};

void Date::setFromTag(vector<string> * tag){
	//TODO implment this
	setMonthDay(0);	
	setMonth(0);	
	setYear(0);	
}

