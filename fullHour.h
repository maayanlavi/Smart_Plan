#pragma once
#include "hour.h"

class fullHour :public Hour  {
public:
	fullHour() :Hour() {
		_AllHoure.push_back("7");
		_AllHoure.push_back("8");
		_AllHoure.push_back("9");
		_AllHoure.push_back("10");
		_AllHoure.push_back("11");
		_AllHoure.push_back("12");
		_AllHoure.push_back("13");
		_AllHoure.push_back("14");
		_AllHoure.push_back("15");
		_AllHoure.push_back("16");
		_AllHoure.push_back("17");
		_AllHoure.push_back("18");
		_AllHoure.push_back("19");
		_AllHoure.push_back("20");
		
	

	}
};