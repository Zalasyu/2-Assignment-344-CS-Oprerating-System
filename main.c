// Author: Alec Moldovan
// Description: Main driver of program.

#include <stdio.h>
#include "coreLogic.h"
#include "ui.h"
#include "error_ui.h"
#include "io.h"

int main(){
	int input = 0;
	menuOne();
	promptOne();
	scanf("%i", &input);
	if (input == 1){
		menuTwo();
		promptTwo();
		scanf("%i", &input);
	}

	return 0;
}

