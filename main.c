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
	// A nested do while loop to handle possible error in input in level 2 of program.
	do {
		stepTwo();
		scanf("%i", &input);
		if (input == 1 ) {



		} else if (input == 2){



		} else if (input == 3){


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

		// If user enter 1, then user wants to process a file.
		if (input == 1){
			levelTwoOfProg();

		} else if ( input == 2 ) {
			return 0;

		} else {
			outOfRange(2);

		}

	} while (true);

	return 0;
}

