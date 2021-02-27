#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<memory>
#include "model.h"
#include "PermanentTask.h"
#include "fullHour.h"


class DayTask {

public:
	DayTask(std::vector<Task*> tasks) {
		_tasks=tasks;
	}
	DayTask() {
		PermanentTask * p =new PermanentTask();
		_tasks.push_back(p);

	}
	
	void setTask(Task* t) {
		_tasks.push_back(t);
	}
	// Task* getTask(int time) {}
	// std::vector<Task*> getTaskDay() {}
	void displayDay() {}
	void deleteTaskByName(std::string s) {}
	void deleteTaskByTime(int time) {}
	void print(){
		for (int i= 0; i<_tasks.size();i++){
			std::cout<<_tasks[i]->getTaskName()<<"\n";
		}
	}
	std::string getNameTaskForPrint(std::string name){
	
		if (name.size() == 10) {
			return name;
		}
		if (name.size() < 10) {
			int numSpace = 10 - name.size();
			for (int i = 0; i < numSpace; i++) {
				name = name + " ";
			}
			return name;
		}
		else {
			return  name.substr(0, 10);
		}
	}
	std::string getNameTaskByTimeStart(int startTime) {
		for (int i = 0; i < _tasks.size(); i++) {
			
			if (startTime == _tasks[i]->getTaskStart()) {
				return getNameTaskForPrint(_tasks[i]->getTaskName());
				
			}
		}
		return "          ";
	
	}


private:
	std::vector<Task*> _tasks;
	
	

};