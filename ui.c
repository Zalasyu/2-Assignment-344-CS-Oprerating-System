// Author: Alec Moldovan
// Description: Contains all functionality for the user interface.

#include <stdio.h>


// Prints the first menu choices.
void menuOne()
{
	printf("1. Select file to process\n2. Exit the program\n");
	return;

}

// Prints a prompt to user asking for an int between 1-2.
void promptOne()
{
	printf("\nEnter a choice 1 or 2: ");
	return;

}

// Encapsulate level one of program's menus and prompts
void stepOne(){
	menuOne();
	promptOne();
	return;

}

// Prints the second menu choices.
void menuTwo()
{
	printf("\nWhich file you want to process?\n");
	printf("Enter 1 to pick the largest file\n");
	printf("Enter 2 to pick the smallest file\n");
  printf("Enter 3 to specify the name of a file\n");
	return;

}

// Prints a prompt asking for an int between 1-3.
void promptTwo()
{
	printf("\nEnter a choice from 1 to 3: ");
	return;

}
void stepTwo(){
	menuTwo();
	promptTwo();
	return;

}

// Prompts user to enter a file name
void promptFileName()
{
	printf("Enter the complete file name: ");
	return;
}
