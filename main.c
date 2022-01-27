// Author: Alec Moldovan
// Description: Main driver of program.

#include <stdio.h>
#include <stdbool.h>
#include "coreLogic.h"
#include "ui.h"
#include "error_ui.h"
#include "io.h"

// FUNCTION DECOMPOSITION: To avoid overly complex (nexted do-while loops with nested if-else) main function.
// Contains flow of program if user chooses and enters 1.
void levelTwoOfProg(){
	int input = 0;
	char str[1000];
	// A nested do while loop to handle possible error in input in level 2 of program.
	do {
		stepTwo();
		scanf("%i", &input);

		// Option 1: Find the LARGEST file with the extension .csv in the current directory
		// AND
		// whose name starts with the prefix 'movies_'
		if (input == 1 ) {
			findLargestFile();



		// Option 2: Find the SMALLEST file with the extension .csv in the current directory
		// AND
		// whose name starts with the prefix 'movies_'
		} else if (input == 2){
			findSmallestFile();


		// Option 3: 
		// 1. Ask user to enter name of file
		// 2. Check if file exists in current directory, if not then print error message
		//		AND
		//		Retry the user with the 3 choices
		} else if (input == 3){
			promptFileName();
			scanf("%s", str);

			findFileByName(str);

		// User did not enter between 1 and 3.
		} else{

			outOfRange(3);

		}

	} while (true);


}

int main(){
	int input = 0;
	// A do-while loop to handle a possible error in input in level 1 of program.
	do {
		stepOne();
		scanf("%i", &input);

		// Option 1: User wants to process a file, therefore go into level 2 of program.
		if (input == 1){
			levelTwoOfProg();

		// Option 2: Exit program successfully.
		} else if ( input == 2 ) {
			return 0;

		// User did not enter between 1 and 2.
		} else {
			outOfRange(2);

		}

	} while (true);

	return 0;
}

