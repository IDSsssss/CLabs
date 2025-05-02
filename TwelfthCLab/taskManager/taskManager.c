#include "taskManager.h"


void chooseTask(const unsigned short choice)
{
	switch (choice)
	{
		case 1:
			addNumbers();
		break;

		case 2:
			deleteHeadAndAddElement();
		break;

		case 3:
			compareQueues();
		break;

		default:;
	}
}