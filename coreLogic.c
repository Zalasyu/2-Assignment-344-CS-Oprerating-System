// Author: Alec Moldovan
// Description: Contain logic for finding the largest, smallest and specific file. Contain logic for parsing out movies by year.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>

#include "movie.h"

#define PREFIX "movies_"
#define SUFFIX ".csv"

void createYearlyMovies()
{

	return;
}

// Check if the file name has the required PREFIX and SUFFIX in its string.
bool checkPrefixSuffix(char *fileName){
	char *end = strrchr(fileName, '.');

	// Compare PREFIX to the first n characters of the file name.
	if(strncmp(PREFIX, fileName, strlen(PREFIX)) == 0){

		// Compare the last letters of file name to .csv
		if( strcmp(end, ".csv") == 0){
			return true;
		}
	}
	return false;

}

void findlargestFile()
{	
	struct stat sb;
	struct dirent *aDir;

	DIR *currDir = opendir("."); // Open current directory

	unsigned int fileSize = 0;
	char *currFileName;

	unsigned int maxFileSize = 0;
	char *maxFileName;

	

	while((aDir = readdir(currDir)) != NULL ){
    currFileName = calloc(strlen(aDir->d_name) + 1, sizeof(char));
		currFileName = aDir->d_name;

		// Check if current file has "movies_" as the prefix
		// AND ".csv" as the suffix
		if (checkPrefixSuffix(currFileName) == true){
			// Get properties of current file.
			stat(currFileName, &sb);

			// Get file size of current file.
			fileSize = (unsigned int)sb.st_size;

			// IF the current file is larger than the current max file size recorded,
			// THEN update the maxFileName variable to the currently largest file.
			if (fileSize > maxFileSize){
				maxFileName = calloc(strlen(currFileName) + 1, sizeof(char));
				maxFileName = currFileName;

			}
		}
		closedir(currDir);
		printf("\nNow processing the chosen file named %s\n", maxFileName);


	}

	return;
}

void findSmallestFile()
{
	struct stat sb;
	return;

}

void findFileByName(const char *file_name)
{
	return;

}
