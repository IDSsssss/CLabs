#include "taskManager.h"

const char* SavedInstancesFilePath = "../Data/data.txt";


void chooseTask(const unsigned short choice)
{
	switch (choice)
	{
		case 1:
			executeTask1();
		break;

		case 2:
			executeTask2(SavedInstancesFilePath);
		break;

		default:;
	}
}