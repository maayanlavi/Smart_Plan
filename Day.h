#pragma once
#include <iostream>
#include <vector>	
#include <string>
#include <memory>



class Day {

public:
	Day(DayTask* dayTask,DayName dayName) {
		_dayTask = dayTask;
		_hour = new fullHour();
		_nameDay = dayName;
		
	}
	Day(std::vector<Task*> tasks,DayName dayName) {
		_dayTask = new DayTask(tasks);
		_hour = new fullHour();
		_nameDay = dayName;
	}
	
	Day(DayName dayName) {
		_dayTask = new DayTask();
		_hour = new fullHour();
		_nameDay = Sunday;
	}
	Day() {
		_dayTask = new DayTask();
		_hour = new fullHour();
		_nameDay = Sunday;
	}
	std::string getNameTaskByStartHour(int startHour) {
		if(_dayTask!=nullptr)
			return _dayTask->getNameTaskByTimeStart(startHour);
		else { return "          "; }
			
	}
	void displayDay(int dayCurrentNum) {
		
		std::cout << std::setw(23) << enumToString(this->_nameDay) << "(" << dayCurrentNum << ")";
		std::cout << "\n----------------------------------------\n";
		if (_dayTask != nullptr) {
			for (int i = 0; i < _hour->getNumHour(); i++) {
				std::cout <<_hour->getNameTimeByIndex(i) << _dayTask->getNameTaskByTimeStart(_hour->getStartTimeByIndex(i)) << "\n\n";
			}
			
		}
		else {
			for (int i = 0; i < _hour->getNumHour(); i++) {
				std::cout << _hour->getNameTimeByIndex(i) << std::setw(10) << "\n\n";
			}
		}
	}
	void displayCommand() {
		std::cout << "Enter w to display all Week" << std::endl;
	}
	std::string enumToString(DayName dayName) {
		switch (dayName) {
		case Sunday:
			return "Sunday";
			break;
		case Monday:
			return "Monday";
			break;
		case Tuesday:
			return "Tuesday";
			break;
		case Wednesday:
			return "Wednesday";
			break;
		case Thursday:
			return "Thursday";
			break;
		case Friday:
			return "Friday";
			break;
		case Saturday:
			return "Saturday";
			break;
		}
	}
private:
	DayTask* _dayTask;
	Hour *_hour;
	DayName _nameDay;
	
};

