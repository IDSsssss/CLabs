#include "inputManager/getInt.h"
#include "taskManager/taskManager.h"

#include <stdio.h>


int main()
{
	while (1)
	{
		printf("\nEnter the task number (1-3) or 4 to exit:\n");
		const int choice = inputIntInRange(1, 4);

		if (choice == 4)
			return 0;

		chooseTask(choice);
	}
}