// Author: Alec Moldovn
// Desctiption: Contain all error handling messages.

#include <stdio.h>


// Error message for promptOne if user doesn't input 1 or 2.
void outOfRange(int i)
{
	printf("\nERROR: Invalid input. Please choose and enter between 1 and %d.\n\n", i);
	return;

}
void FileDNE(const char *file_name)
{
	printf("\nThe file '%s' does not exist. Please, try again.", file_name);
	return;
}
