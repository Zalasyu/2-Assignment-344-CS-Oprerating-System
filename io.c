// Author: Alec Moldovan
// Description: Contains all logic for I/O operaionts like importing and parsing a CSV file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "error_ui.h"
#include "movie.h"


/* Parse the current line which is space delimited and create a
*  movie struct with the data in this line
*/
struct movie *createMovie(char *currLine)
{
    struct movie *currMovie = malloc(sizeof(struct movie));

    // Context for strtok_r (re-entrant function) [third argument]
    // char* saveptr;
    // strtok_r returns next token.
    char* token;

    // The first token is the movie title
    token = strtok(currLine, ",");
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the year
    token = strtok(NULL, ",");
    currMovie->year = atoi(token);

    // The next token is the lang
    token = strtok(NULL, ",");
    currMovie->lang = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->lang, token);

    // The last token is the rating
    token = strtok(NULL, "\n");
    currMovie->rating = strtof(token, NULL);

    // Set the next node to NULL in the newly created movie entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Return a linked list of movies by parsing data from
* each line of the specified file.
*/
struct movie *processFile(char *filePath)
{
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

    char *currLine = NULL;
    size_t len = 0;
    size_t nread;

    // The head of the linked list
    struct movie *head = NULL;
    // The tail of the linked list
    struct movie *tail = NULL;

    // Skip first line of CSV file
    getline(&currLine, &len, movieFile);
    
    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        // Get a new movie node corresponding to the current line
        struct movie *newNode = createMovie(currLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    free(currLine);
    fclose(movieFile);
    return head;
}


