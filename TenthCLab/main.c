#include "inputManager/getInt.h"
#include "taskManager/taskManager.h"

#include <stdio.h>


int main()
{
	while (1)
	{
		printf("\nEnter the task number (1-2) or 3 to exit:\n");
		const int choice = inputIntInRange(1, 3);

		if (choice == 3)
			return 0;

		chooseTask(choice);
	}
}