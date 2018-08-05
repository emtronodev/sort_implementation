#ifndef RANDOM_H
#define RANDOM_H

/* Define min and max limits of integers here */
#define INT_MINIMUM 0
#define INT_MAXIMUM 99999
/* Define min and max limits of doubles here */
#define DBL_MINIMUM 0.0
#define DBL_MAXIMUM 1.0

int random_int(int seed);
double random_double(int seed);

#endif
