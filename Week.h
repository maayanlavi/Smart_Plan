#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <conio.h>
#include <chrono>
#include <time.h> 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <ctime>
#include <iomanip>
#include "Day.h"

class Week {

public:
	Week() {
		_hour = new fullHour();
		time_t t = time(0);   // get time now
		struct tm * now = localtime(&t);
		_currentDay = now->tm_mday;
		_weekDay = now->tm_wday;
		_currentYear = now->tm_year;
		_currentmonth = now->tm_mon;
		
		_numberOfDays = getNumberOfDays(now->tm_mon + 1, now->tm_year);
	}
	Week(std::map <DayName, Day*> tasks) {
		_tasks = tasks;
		_hour = new fullHour();
		time_t t = time(0);   // get time now
		struct tm * now = localtime(&t);
		_currentDay = now->tm_mday;
		_weekDay = now->tm_wday;
		_currentYear = now->tm_year+ 1900;
		_currentmonth = now->tm_mon+1;
		_numberOfDays = getNumberOfDays(now->tm_mon + 1, now->tm_year);
		
	}
		
	void printTask(){
		for (auto const& p : _tasks){
			
	 	 p.second->print();
		  std::cout<<"\n";
		}

   

	}
	int getCurrentNumDay() { return _currentDay; }
	void addTask(Task* task){
		
		_tasks[task->getTaskDay()]->addTask(task);
	}
	int  getNumberOfDays(int month, int year)
	{
		//leap year condition, if month is 2
		if (month == 2)
		{
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
				return 29;
			else
				return 28;
		}
		//months which has 31 days
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
			return 31;
		else
			return 30;
	}
	
	void displayWeek() {
		std::cout<<"year: "<<_currentYear<<"\n";
		int day = _currentDay;
		int weekDay = _weekDay;
		for (int i = 0; i < 7; i++) {
			if (day > _numberOfDays) {
				day = 1;
			}
			if (weekDay == 7) {
				weekDay = 0;
			}
			if (i == 0) {
				std::cout << std::setw(23) << _tasks[DayName(weekDay)]->enumToString(DayName(weekDay)) << "(" << day << ")";
			}
			else {
				std::cout << std::setw(11) << _tasks[DayName(weekDay)]->enumToString(DayName(weekDay)) << "(" << day << ")";
			}
			day++;
			weekDay++;

		}
		std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < _hour->getNumHour(); i++) {
			int startTime = _hour->getStartTimeByIndex(i);
			std::cout << _hour->getNameTimeByIndex(i)
				<< _tasks[Sunday]->getNameTaskByStartHour(startTime)
				<< _tasks[Monday]->getNameTaskByStartHour(startTime)
				<< _tasks[Tuesday]->getNameTaskByStartHour(startTime)
				<< _tasks[Wednesday]->getNameTaskByStartHour(startTime)
				<< _tasks[Thursday]->getNameTaskByStartHour(startTime)
				<< _tasks[Friday]->getNameTaskByStartHour(startTime)
				<< _tasks[Saturday]->getNameTaskByStartHour(startTime) << "\n\n";
		}
	}
	void displayCommand() {
		std::cout << "Enter d to display one Day" << std::endl;
		std::cout << "Enter a to add task" << std::endl;
	}
	Day* getDayTaskByNameOfDay(DayName dayName) {
		return _tasks[dayName];
	}
	std::vector<std::string> getLastWeek(){
		std::vector<std::string> alldateWeek;
		int day=_currentDay;
		int month=_currentmonth;
		int year=_currentYear;
		int numDay=_numberOfDays;
		
		for (int i = 0; i < 7; i++) {
			std::string _lastDayWeek;
			if (day >numDay) {
				day = 1;
				month=month+1;
			if(month >12 ){
				year=year+1;
				month=1;
			}
			}
				_lastDayWeek = std::to_string(day);
				_lastDayWeek+=",";
				_lastDayWeek+=std::to_string(month);
				_lastDayWeek+=",";
				_lastDayWeek+=std::to_string(year);
				std::cout<<_lastDayWeek<<"\n";
			    alldateWeek.push_back(_lastDayWeek);
				day++;
		}
	
	return alldateWeek;
	}
std::string getFulldateTask(DayName n){
	int theMonth=-1;
	int dayinmonth=-1;
	int year=-1;
	int numDay= dayNameToint(n);
	int numDayMonth=numDay-_weekDay;
	if(numDayMonth<0){
		numDayMonth=7+numDay-_weekDay;
	}
	dayinmonth=numDayMonth+_currentDay;
	if(dayinmonth>_numberOfDays){
		theMonth=_currentmonth+1;
		if(theMonth>12){
			year=year+1;
			theMonth=1;
		}
		else{
			year=_currentYear;
		}
		dayinmonth=dayinmonth-_numberOfDays;
	}
	else{
		theMonth=_currentmonth;
		dayinmonth=dayinmonth-_numberOfDays;
	}
		std::string stringDate;
		stringDate = std::to_string(dayinmonth);
		stringDate+=",";
		stringDate+=std::to_string(theMonth);
		stringDate+=",";
		stringDate+=std::to_string(year);
		return stringDate;

}
private:
	std::map<DayName, Day*> _tasks;
	Hour *_hour;
	int _currentDay;
	int _weekDay;
	int _currentYear;
	int _currentmonth;
	int _numberOfDays;
	int dayNameToint(DayName n){
		if(n==Sunday){
			return 1;
		}
		if(n==Monday){return 2;}
		if(n==Tuesday){return 3;}	
		if(n==Wednesday){return 4;}
		if(n==Thursday){return 5;}
		if(n== Friday){return 6;}
		if(n==Saturday){return 7;}
		else{return -1;}
	}
};

