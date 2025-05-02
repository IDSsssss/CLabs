#include "taskManager.h"


void chooseTask(const unsigned short choice)
{
	switch (choice)
	{
		case 1:
			addEvenNumbers();
		break;

		case 2:
			mergeStacks();
		break;

		default:;
	}
}