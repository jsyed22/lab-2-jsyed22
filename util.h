#ifndef UTILH
#define UTILH
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

typedef unsigned int uint;

//An array of random uints of size size, with values between
//smallest and one less than larger.  Assumes a properly
//initialized srand()
uint * RandomArray(uint size, uint smallest, uint larger);

//Print out an array of the sort above
void PrintArray(uint array[], uint size);

//Print an error message to stderr
void PrintError(char * message);

//Print our standard usage message
void PrintUsage();

//Test function that is used to demonstrate how Timefunction works
void CountTo(uint upperlimit);

#endif
