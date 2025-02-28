/**/

#include "../textFiles/textFiles.h"


void task1(FileDescriptor* file_descriptor)
{
	puts("Your file is:");
	printFile(file_descriptor);



	celectMethodOfFillingFile(file_descriptor);



	puts("Your file is:");
	printFile(file_descriptor);
}