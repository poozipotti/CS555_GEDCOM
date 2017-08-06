#ifndef _DATE_H_
#define _DATE_H_

//Date is a class instead of a struct becuase it will contain error checking and can be given a tag in it's constructor
//the date class uses '0' to denote that no value has been assigned yet, all counting starts at 1
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

class Date{
	private:
		int month;
		int monthDay;
		int year;
		const string MONTHS[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
		const  int NUMBER_OF_MONTHS = 12;
	public:
        struct tm * timeStruct;
		//will initilize a date with (0,0,0)
		Date ():Date(time(0)){};
        Date (int _month,int _day,int _year);
		Date( string _month, int _day, int _year);
        Date(time_t);
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
        //subtract reuturns a vector that in the format of [years.months,days] between two dates
        static int  getDaysBetween(Date* ,Date* );
        static int  getYearsBetween(Date* ,Date* );
		bool operator==(const Date& d){
			return (month == d.month && monthDay == d.monthDay && d.year == year);
		}
		bool operator<(const Date& d){
			if(year < d.year){
				return true;
			}else if(year > d.year){
				return false;
			}else if(month < d.month){
				return true;
			}else if(month > d.month){
				return false;
			}else if(monthDay < d.monthDay){
				return true;
			}else{
				return false;
			}
		}
		bool operator>(const Date& d){
			if(year > d.year){
				return true;
			}else if(year < d.year){
				return false;
			}else if(month > d.month){
				return true;
			}else if(month < d.month){
				return false;
			}else if(monthDay > d.monthDay){
				return true;
			}else{
				return false;
			}
		}
		void setMonth(int);
		void setMonth(string);
		void setMonthDay(int);
		void setYear(int);
        string toString(){
            return(to_string(month)+"/"+to_string(monthDay)+"/"+to_string(year));
        };
};

#endif
