// Author: Alec Moldovan
// Contain function prototypes for io.c to handle input and output functionality.
#ifndef IO_H_
#define IO_H_

// Read and parse a CSV file
struct movie *processFile(char *filePath);
void printMovieList(struct movie *list);

#endif
