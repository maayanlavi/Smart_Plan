#include <iostream>
#include "model.h"
#include "observable.h"
#include <fstream>

#pragma once

class PermanentTask;
class OccasionalTask;
class mySQLModel : public model , public observable {
public:
	mySQLModel(): model(),observable(){
		
		myfile.open ("MyTasks.txt", std::ofstream::app);
		
	}

	void saveTaskToFile(std::string taskToFile);

	Task loadFromFile();
	virtual void setTask(TYPE_TASK typeTask, std::string inputUser);
	virtual ~mySQLModel() {myfile.close();}
private:
	std::ofstream myfile;
	Task * _hendleTask;

};
