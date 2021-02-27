#include "mySQLModel.h"

	void mySQLModel::saveTaskToFile(std::string taskToFile)
    {
        myfile << taskToFile << std::endl;
        this->~mySQLModel();
    }

	// Task mySQLModel::loadFromFile() {
	// 		std::ifstream infile("MyTasks.txt");
	// 		std::string name;
	// 		std::string end;
	// 		std::string start;
	// 		std::string category;
	// 		std::string day;
	// 		std::string strDay;
	// 		std::string strCat;
	// 		while (!infile.eof())
	// 			{
	// 				std::getline(infile, name);
	// 				std::getline(infile, end);
	// 				std::getline(infile, start);
	// 				std::getline(infile, category);
	// 				std::getline(infile, day);
	// 				std::getline(infile, strDay);
	// 				std::getline(infile, strCat);
	// 			}	
	// 	}

	void mySQLModel::setTask(TYPE_TASK typeTask, std::string inputUser){
		if(typeTask == Permanent){
			PermanentTask *task = new PermanentTask(inputUser);
			std::string name =task->getTaskName();
			int end = task->getTaskEnd();
			int start = task->getTaskStart();
			Category category = task->getTaskCategory();
			DayName day = task ->getTaskDay();
			std::string strDay = task->enumDayToString(day);
			std::string strCat = task->enumCategoryToString(category);         
			std::string mergeTask;
            mergeTask+= name+std::to_string(start);
            mergeTask+=std::to_string(end);
            mergeTask+=strDay;
            mergeTask+=strCat;
            saveTaskToFile(mergeTask);
		}
		else{
			OccasionalTask* task= new OccasionalTask(inputUser);
			std::string name =task->getTaskName();
			std::pair<int,int> startEnd = task->schedulingAlgorithm(task ->getTaskDay(), task->getDeadline(), myfile);
			int start= startEnd.first;
			int end =startEnd.second;
			Category category = task->getTaskCategory();
			DayName day = task ->getTaskDay();
			std::string strDay = task->enumDayToString(day);
			std::string strCat = task->enumCategoryToString(category);
			std::string mergeTask;
            mergeTask+=name+std::to_string(start);
            mergeTask+=std::to_string(end);
            mergeTask+=strDay;
            mergeTask+=strCat;
			std::cout<<mergeTask;
            saveTaskToFile(mergeTask);

		}
        		
	}
