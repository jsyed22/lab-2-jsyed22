#include "util.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


//An array of random uints of size size, with values between
//smallest and one less than larger.  Assumes a properly
//initialized srand()
uint * RandomArray(uint size, uint smallest, uint larger)
{
   uint * array = malloc(size * sizeof(uint));
   if(array)
      for(int i = 0; i < size; ++i)
        array[i]=rand()%(larger-smallest) + smallest;
   return array;
}

//Print out an array of the sort above
void PrintArray(uint array[], uint size)
{
  for (uint i=0; i < size; ++i)
    printf("%d ",array[i]);
  printf("\n");
}

//Print an error message to stderr
void PrintError(char * message)
{
  fprintf(stderr,ANSI_COLOR_RED "Error:" ANSI_COLOR_RESET);
  fprintf(stderr,message);
  fprintf(stderr,"\n");
}

//Print our standard usage message
void PrintUsage(char * appname)
{
  printf(ANSI_COLOR_BLUE "Usage:" ANSI_COLOR_RESET);
  printf("%s <n>",appname);
  printf(" - where <n> is the number of elements in the random array.\n");
}
