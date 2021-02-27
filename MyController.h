#pragma once
#include "Controller.h"
#include "OccasionalTask.h"
#include "PermanentTask.h"
#include "mySQLModel.h"

class MyController : Controller {
public:
	MyController(model* model, view* view) : Controller(model, view) {
		std::map<DayName, Day*> tasks;
		
		tasks[Sunday]= new Day(Sunday);
		tasks[Monday] = new Day(Monday);
		tasks[Tuesday] = new Day(Tuesday);
		tasks[Wednesday] = new Day(Wednesday);
		tasks[Thursday] = new Day(Thursday);
		tasks[Friday] = new Day(Friday);
		tasks[Saturday] = new Day(Saturday);
		Week *week = new Week(tasks);
		if (typeid(*view) == typeid(MyView)) {
		((MyView*)view)->setWeek(week);
		((MyView*)view)->displayTask(Sunday);
	}
		std::cout<<week->getLastWeek();
		start();
	}
	virtual void start() {
		std::string input;
		std::string inputB;
		std::string req;
		input = _view->getInputUser();
		while (input != "q") {
			if (input == "w") {
				_view->changeTypeView(WEEK);
			}
			if (input == "d") {
				_view->changeTypeView(DAY);
			}
			if (input == "a") {
				_view->printReqUser("choose o or p task");
				inputB = _view->getInputUser();
			}
			if (inputB == "o") {
				_view->printReqUser("enter <name>,<catagory>,<dayName>,<deadline>:\n");
				_model->setTask(Occasional, _view->getInputUser());
					
			}
			if (inputB == "p") {
				_view->printReqUser("enter <name>,<catagory>,<dayName>,<star hour>,<end hour>:\n");
				_model->setTask(Permanent, _view->getInputUser());
			}
			input = _view->getInputUser();
		
		}
	
	}
};