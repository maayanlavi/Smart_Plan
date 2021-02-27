#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "DayTask.h"

#pragma once

class Hour {

public:
	Hour() {
	}
	void displayDay() {}
	std::vector<std::string>  getAllHours() { return _AllHoure; }
	int getNumHour() {
		return _AllHoure.size();
	}
	std::string getNameTimeByIndex(int index) {
		return _AllHoure.at(index);
	}
	int getStartTimeByIndex(int index) {
		int hour = atoi(_AllHoure[index].c_str());
		return hour;

	}
protected:
	std::vector<std::string>  _AllHoure;
};
