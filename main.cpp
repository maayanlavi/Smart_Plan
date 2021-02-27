#include <iostream>
#include <iomanip>
#include "MyView.h"
#include "MyController.h"
#include "mySQLModel.cpp"
int main()
{	
	std::cout<<"fdsfdsf";
	mySQLModel* mo = new mySQLModel();
	MyView *v = new MyView();
	MyController* c= new MyController(mo,v);
}