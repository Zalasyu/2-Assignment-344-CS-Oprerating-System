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
#include <limits.h>

#include "movie.h"
#include "io.h"
#include "error_ui.h"

#define PREFIX "movies_"
#define SUFFIX ".csv"

void createYearlyMovies()
{

	return;
}

// Check if the file name has the required PREFIX and SUFFIX in its string.
bool checkPrefixSuffix(char *fileName)
{
	char *end = strrchr(fileName, '.');
	printf("\nThe suffix of this file is: %s\n", end);
	if (end == NULL){
		return false;
	}

	// Compare PREFIX to the first n characters of the file name.
	if(strncmp(PREFIX, fileName, strlen(PREFIX)) == 0){

		// Compare the last letters of file name to .csv
		if( strcmp(end, SUFFIX) == 0){
			return true;
		}
	}
	return false;

}

void findLargestFile()
{	
	DIR *currDir = opendir("."); // Open current directory

	struct stat sb;
	struct dirent *aDir;


	unsigned int fileSize = 0;
	char currFileName[256];

	unsigned int maxFileSize = 0;
	char maxFileName[256];

	

	while((aDir = readdir(currDir)) != NULL ){

		memset(currFileName, '\0', sizeof(currFileName));
		strcpy(currFileName, aDir->d_name);
		printf("\nCurrent File: %s\n", aDir->d_name);

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
				printf("\nThe current file is %s and its file size is %u\n", currFileName, fileSize);
				printf("\nThe max file is %s and its file size is %u\n", maxFileName, maxFileSize);
				memset(maxFileName, '\0', sizeof(maxFileName));
				strcpy(maxFileName, currFileName);
				maxFileSize = fileSize;

			}
		}
	}
	// Close the directory.
	closedir(currDir);
	printf("\nNow processing the chosen file named %s\n", maxFileName);

	return;
}

void findSmallestFile()
{
	DIR *currDir = opendir("."); // Open current directory

	struct stat sb;
	struct dirent *aDir;


	unsigned int fileSize = 0;
	char currFileName[256];

	unsigned int minFileSize = UINT_MAX;
	char minFileName[256];

	

	while((aDir = readdir(currDir)) != NULL ){

		memset(currFileName, '\0', sizeof(currFileName));
		strcpy(currFileName, aDir->d_name);
		printf("\nCurrent File: %s\n", aDir->d_name);

		// Check if current file has "movies_" as the prefix
		// AND ".csv" as the suffix
		if (checkPrefixSuffix(currFileName) == true){
			// Get properties of current file.
			stat(currFileName, &sb);

			// Get file size of current file.
			fileSize = (unsigned int)sb.st_size;
			printf("\nThe current file is %s and its file size is %u\n", currFileName, fileSize);

			// IF the current file is smaller than the current min file size recorded,
			// THEN update the minFileName variable to the currently largest file.
			if (fileSize < minFileSize){
				printf("\nThe current file is %s and its file size is %u\n", currFileName, fileSize);
				printf("\nThe min file is %s and its file size is %u\n", minFileName, minFileSize);
				memset(minFileName, '\0', sizeof(minFileName));
				strcpy(minFileName, currFileName);
				minFileSize = fileSize;

			}
		}
	}
	// Close the directory.
	closedir(currDir);
	printf("\nNow processing the chosen file named %s\n", minFileName);

	return;

}

void findFileByName(const char *input)
{
	DIR *currDir = opendir("."); // Open current directory

	struct stat sb;
	struct dirent *aDir;
	
	bool res = false;


	while((aDir = readdir(currDir)) != NULL){
		if(strcmp(aDir->d_name, input) == 0){
			res = true;
		}
	}
	// Close the directory
	closedir(currDir);

	// IF the file was found
	if (res){
		printf("\nNow processing the chosen file named %s\n", input);

	} else {
		FileDNE(input);

	}

	return;

}
