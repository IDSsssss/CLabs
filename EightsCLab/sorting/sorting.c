#include "../binaryFiles/binaryFiles.h"


static void sortFileByHoaresMethod(FILE* file, const int first_index, const int second_index)
{
	if (first_index >= second_index)
		return;

	const int support_element = getNumber(file, second_index);

	int i = first_index;
	int j = second_index;

	while (i <= j)
	{
		while (getNumber(file, i) > support_element)
			++i;

		while (getNumber(file, j) < support_element)
			--j;

		if (i <= j)
		{
			swapNumbers(file, j, i);

			++i;
			--j;
		}
	}

	sortFileByHoaresMethod(file, first_index, j);
	sortFileByHoaresMethod(file, i, second_index);
}


void sortFile(FILE* file)
{
	sortFileByHoaresMethod(file, 0, calculateFileLength(file) - 1);
}