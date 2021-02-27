#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Task.h"



class OccasionalTask : public Task {
public:
	OccasionalTask(std::string name, Category category, DayName dayName, DayName DayDeadline, int HourDeadline)
		: Task(name, category) {
		
		_HourDeadline = HourDeadline;
	}
	OccasionalTask(std::string str)
		: Task()
	{
		std::vector<std::string> arr;
		arr = split(str, ",");
		_name= arr[0];
		_category =stringCatagory(arr[1]);
		_dayName =stringDay(arr[2]);
		_HourDeadline = atoi( arr[3].c_str() );
		
	}
	bool checkValidation(std::string strInputUser){
		std::vector<std::string> vec;
		vec = split(strInputUser, ",");
		if (vec.size() != 4){
			return false;
		}
		Category c= stringCatagory(vec[1]);
		if(c==ErrorCat){
			return false;
		}
		DayName d= stringDay(vec[2]);
		if(d==Error){
			return false;
		}
		try{
			int de=atoi(vec[3].c_str());
			
		}
		catch(...){
 				return false;
		}
	}
std::pair<DayName, int> schedulingAlgorithm(DayName day, int deadline, std::ofstream& file){
	//TO DO impliment this algoritham
	//for tests the algoritham return deafult value
	std::ifstream infile("MyTasks.txt");
	std::string line;
	while (std::getline(infile,line))
	{
		
		const char space[] = "-"; 
		char *token;
		//token = strtok(line, space);

	}


	

	 return std::make_pair(Sunday, 4);
}
int getDeadline(){return _HourDeadline;}

friend std::ostream& operator <<(std::ostream& os, const OccasionalTask& o);
private:
	int _HourDeadline;


};
