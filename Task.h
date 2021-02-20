  
#include <iostream>
#include <string>
#pragma once


enum Category
{
	Sport,
	Study,
	Family,
	Personal,
	Work
};


enum DayName
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};


class Task {
public:
	Task() {}
	Task(std::string name, Category category) {}
	std::string getTaskName() { return _name; }
	std::string getTaskStart() { return _start; }
	int getTaskEnd() {}
	Category getTaskCategory() {}
	DayName getTaskDay() {}

	void setTaskName(std::string name) {}
	void setTaskStart(int start) {}
	void setTaskEnd(int end) {}
	void setTaskCategory(Category category) {}
	void setTaskDay(DayName dayName) {}
	

private:
	std::string _start;
	std::string _end;
	std::string _name;
	Category _category;
	DayName _dayName;


};