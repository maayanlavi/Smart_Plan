#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

enum TYPE_TASK{
	Occasional,
	Permanent
};
enum Category
{
	Sport,
	Study,
	Family,
	Personal,
	Work,
	ErrorCat
};


enum DayName
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Error
};


class Task {
public:
	Task() {}
	Task(std::string name, Category category) {}
	std::string enumDayToString(DayName dayName) {
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
	
	std::string enumCategoryToString(Category category) {
		switch (category) {
		case Sport:
			return "sport";
			break;
		case Study:
			return "study";
			break;
		case Family:
			return "family";
			break;
		case Personal:
			return "personal";
			break;
		case Work:
			return "work";
			break;
		}
	}
	std::vector<std::string> split(std::string str, std::string sep) {
		char* cstr = const_cast<char*>(str.c_str());
		char* current;
		std::vector<std::string> arr;
		current = strtok(cstr, sep.c_str());
		while (current != nullptr) {
			arr.push_back(current);
			current = strtok(nullptr, sep.c_str());
		}
		return arr;
	}
	std::string getTaskName() { return _name; }
	int getTaskStart() { return _start; }
	int getTaskEnd() {return _end;}
	Category getTaskCategory() {return _category;}
	DayName getTaskDay() {return _dayName;}
	
	void setTaskName(std::string name) {}
	void setTaskStart(int start) {}
	void setTaskEnd(int end) {}
	void setTaskCategory(Category category) {}
	void setTaskDay(DayName dayName) {}
	void print(){}

protected:
	int _start;
	int _end;
	std::string _name;
	Category _category;
	DayName _dayName;
	Category stringCatagory(std::string c) {
		if (c == "sport") {
			return Sport;
		}
		if (c == "study") {
			return Study;
		}
		if (c == "family") {
			return Family;
		}
		if (c == "personal") {
			return Personal;
		}
		if (c == "work") {
			return Work;
		}
		else{return ErrorCat;}
		
	}
	DayName stringDay(std::string c) {
		if (c == "sunday") {
			return Sunday;
		}
		if (c == "monday") {
			return Monday;
		}
		if (c == "tuesday") {
			return Tuesday;
		}
		if (c == "thursday") {
			return Thursday;
		}
		if (c == "wednesday") {
			return Wednesday;
		}
		if (c == "friday") {
			return Friday;
		}
		if (c == "saturday") {
			return Saturday;
		}
		else{return Error;}
		
	}

};

