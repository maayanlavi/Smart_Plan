#include <iostream>
#include "model.h"
#include "observable.h"
#include <fstream>

#pragma once

class PermanentTask;
class OccasionalTask;
class mySQLModel : public model, public observable
{
public:
	mySQLModel() : model(), observable()
	{

		myfile.open("MyTasks.txt", std::ofstream::app);
		std::ifstream infile("MyTasks.txt");
		std::string line;
		char c = '.';
		while (std::getline(infile, line))
		{
			std::string newDate;
			for (int i = 0; i < line.length(); ++i)
			{
				if (line[i] == c)
					break;
				newDate += line[i];
			}
			//if (!IsInTheWeek(newDate))
				//delete this line from file

		}
	}

	void saveTaskToFile(std::string taskToFile);

	bool IsInTheWeek(std::string date)
	{
		return true;
	}

	Task loadFromFile();
	virtual void setTask(TYPE_TASK typeTask, std::string inputUser);
	virtual ~mySQLModel() { myfile.close(); }

private:
	std::ofstream myfile;
	Task *_hendleTask;
};
