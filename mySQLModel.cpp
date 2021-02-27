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
		w->printTask();
		if(typeTask == Permanent){
			
			PermanentTask *task = new PermanentTask(inputUser);
			w->addTask(task);
			std::string name =task->getTaskName();
			int end = task->getTaskEnd();
			int start = task->getTaskStart();
			Category category = task->getTaskCategory();
			DayName day = task ->getTaskDay();
			std::string strDay = task->enumDayToString(day);
			std::string strCat = task->enumCategoryToString(category);         
			std::string mergeTask;
            mergeTask+= w->getFulldateTask(day);
            mergeTask+='.';
            mergeTask+= name;
            mergeTask+='.';
            mergeTask+=std::to_string(start);
            mergeTask+='.';
            mergeTask+=std::to_string(end);
            mergeTask+='.';
            mergeTask+=strDay;
            mergeTask+='.';
            mergeTask+=strCat;
            saveTaskToFile(mergeTask);
            std::cout << "the Task added successfully!" << std::endl;

		}
		else{
			OccasionalTask* task= new OccasionalTask(inputUser);
			std::string name =task->getTaskName();
			w->addTask(task);
			//std::pair<int,int> startEnd = task->schedulingAlgorithm(task->getDeadline());
			int start= 7;
			int end =7;
			Category category = task->getTaskCategory();
			DayName day = task ->getTaskDay();
			std::string strDay = task->enumDayToString(day);
			std::string strCat = task->enumCategoryToString(category);
			std::string mergeTask;
            mergeTask+= w->getFulldateTask(day);
            mergeTask+='.';
            mergeTask+=name+std::to_string(start);
            mergeTask+='.';
            mergeTask+=std::to_string(end);
            mergeTask+='.';
            mergeTask+=strDay;
            mergeTask+='.';
            mergeTask+=strCat;
            saveTaskToFile(mergeTask);
            std::cout << "the Task added successfully!" << std::endl;

		}
        std::cout<<"print after add "<<"\n";
		w->printTask();		
	}

std::vector<std::string> mySQLModel::allTasksFromFile() {
    std::vector<std::string> res;
    std::string line;
    std::ifstream infile("MyTask.txt");
    while (std::getline(infile, line))
    {
        res.push_back(line);
    }
    return res;

}