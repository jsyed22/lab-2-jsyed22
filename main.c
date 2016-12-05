#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util.h"
#include "search.h"
#include "sort.h"

#define MINVAL 0 //Inclusive minimum value
#define MAXVAL n //Exclusive maximum value (nb: using n as MAXVAL)

int main(int argc, char** argv)
{
  //Create a reusable seed.
  int seed = time(NULL);
  long n = 0; //Number of elements (retrieved from CL)
  char * endptr = NULL; //For error detection in CL number
  uint * set = NULL; //Our array of numbers on heap
  uint val = 0; //Value to search for (set later)
  int loc = 0; //Location for search values

  //Get parameters for CL args
  if(argc != 2)
  {
    PrintError("Invalid number of arguments");
    PrintUsage(argv[0]); //Pass the name of our executable
    return -1;
  }

  //Try to convert our one arg to a long int
  n = strtol(argv[1],&endptr,10); //Base 10 number

  if(*endptr != 0) //Junk in command Line
  {
    PrintError("Unrecognized characters. N should be a whole number.");
    PrintUsage(argv[0]); //Pass the name of our executable
    return -2;
  }

  if (n <= 0)
  {
    PrintError("Negative or zero value. N should be a whole number.");
    PrintUsage(argv[0]); //Pass the name of our executable
    return -3;
  }

  //Seed for rand
  srand(seed);

  //Get a random array of the specified size, range
  set = RandomArray(n,MINVAL,MAXVAL);
  if(!set)
  {
    PrintError("Memory allocation error. Unable to instantiate set.");
    return -5;
  }
  //For testing.  Uncomment or move line below to print array contents
  //PrintArray(set,n);

  //Get a random value to search for that is in our range
  val = rand()%(MAXVAL-MINVAL) + MINVAL;

  //Search for our random number (sequential) and print time.
  printf("Performing sequential search for %d in array with %lu values...\n",
    val,n);
  loc = TimeSearch(SeqSearch,val,set,n);
  if (loc >= 0) printf("Value found at location %d\n", loc);
  else printf("Value not found.\n");
  printf("\n");

  //Bubble sort them
  printf("Bubble sorting array...\n");
  TimeSort(BubSort,set,n);
  printf("\n");

  //Search for our number again (binary)
  printf("Performing Binary search for %d in array with %lu values...\n",
    val,n);
  loc = TimeSearch(BinSearch,val,set,n);
  if (loc >= 0) printf("Value found at location %d\n", loc);
  else printf("Value not found.\n");
  printf("\n");

  //Clean up our toys prior to reusing pointer
  if(set)
  {
    free(set);
    set = NULL;
  }

  //Recreate the array, using the same seed.
  srand(seed);
  set = RandomArray(n,MINVAL,MAXVAL);
  if(!set)
  {
    PrintError("Memory allocation error. Unable to instantiate set.");
    return -5;
  }

  //Selection sort them
  printf("Selection sorting array...\n");
  TimeSort(SelSort,set,n);
  printf("\n");

  //Search for our number again (binary)
  printf("Performing Binary search for %d in array with %lu values...\n",
    val,n);
  loc = TimeSearch(BinSearchRec,val,set,n);
  if (loc >= 0) printf("Value found at location %d\n", loc);
  else printf("Value not found.\n");
  printf("\n");

  //All done. Clean up.
  if(set)
  {
    free(set);
    set = NULL;
  }
  return 0;
}
