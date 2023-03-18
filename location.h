#include <stdlib.h>
#include <string.h>

#ifndef LOCATION_H_
#define LOCATION_H_

typedef struct _location location;

struct _location{
    char const * title;
    char const * description;
    char const * object;
};

void printLocation(location crnt_loc);

location forward(location nxt_loc);

int prompt(location crnt_loc);

void advance(location crnt_loc, location nxt_loc);

#endif