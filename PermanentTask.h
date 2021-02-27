#include <iostream>
#include <string>
#include "Task.h"
#pragma once



class PermanentTask : public Task {
public:
	PermanentTask(int start, int end, std::string name, Category category, DayName dayName) : Task(name, category) {
		_dayName = dayName;
		_start = start;
		_end = end;
	}

	
	PermanentTask(std::string str)
			: Task()
		{
			bool valid = checkValidation(str);
			if (valid == false){
				std::cout << "error";
			}
			else{
				std::vector<std::string> arr;
				arr = split(str, ",");
				_name = arr[0];
				_category = stringCatagory(arr[1]);
				_dayName = stringDay(arr[2]);
				_start = atoi(arr[3].c_str());
				_end = atoi(arr[4].c_str());
			}
			

		}
	
	bool checkValidation(std::string strInputUser){
		std::vector<std::string> vec;
		vec = split(strInputUser, ",");

		if (vec.size() != 5){
			return false;
		}
		Category c= stringCatagory(vec[1]);
		if(c == ErrorCat){
			return false;
		}
		DayName d= stringDay(vec[2]);
		if(d == Error){
			return false;
		}
		try{
			int s=atoi(vec[3].c_str());
			int e= atoi(vec[4].c_str());
		}
		catch(...){
 				return false;
		}

		return true;

	}


};