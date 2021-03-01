#include <iostream>
#include <iomanip>
#include "MyView.h"
#include "MyController.h"
#include "MyModel.cpp"
int main()
{	
	MyModel* mo = new MyModel();
	MyView *v = new MyView();
	MyController* c= new MyController(mo,v);
}
