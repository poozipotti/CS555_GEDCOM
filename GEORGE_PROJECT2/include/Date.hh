#ifndef _DATE_H
#define _DATE_H_
//Date is a class instead of a struct becuase it will contain error checking and can be given a tag in it's constructor
//the date class uses '0' to denote that no value has been assigned yet, all counting starts at 1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date{
	private:
		int month;
		int monthDay;
		int year; 
		const string MONTHS[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
		const  int NUMBER_OF_MONTHS = 12;
	public:
		//will initilize a date with (0,0,0)
		Date ():Date(0,0,0){};	
	        Date (int _month,int _day,int _year);	
		Date( string _month, int _day, int _year);
		//will initilize a date from tag data
	        Date (vector<string> *);	

		void setFromTag(vector<string> *);		

		int getMonth(){
			return month;
		}
		int getMonthDay(){
			return monthDay;
		}
		int getYear(){
			return year;
		}	
		bool operator==(const Date& d){
			return (month == d.month && monthDay == d.monthDay && d.year == year);
		}
		void setMonth(int);	
		void setMonth(string);
		void setMonthDay(int);	
		void setYear(int);	
		string toString();
};
#endif