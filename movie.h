#ifndef MOVIE_H_
#define MOVIE_H_

// Define movie struct
struct movie{
  char *title;
  char *lang;
  float rating;
  int year;
  struct movie *next;
};

#endif

