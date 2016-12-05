#include "search.h"
#include <stdio.h>
#include <time.h>

//Do a search, but time it. Returns index of found item, prints cpu time in msec
int TimeSearch(int (*fctn)(uint, uint *, uint),uint key,uint set[],uint size)
{
    int retval = 0; //Result of search
    clock_t diff = 0;
    clock_t start = clock();
    retval = fctn(key,set,size); //Search, but ignore return value
    diff = clock() - start;
    printf("Search completed in %lu msec.\n", diff*1000/CLOCKS_PER_SEC);
    return retval;
}

//Linear Search - return index of key in set, or -1
int SeqSearch(uint key, uint set[], uint size)
{
   for(uint i = 0; i < size; ++i)
   {
     if (key == set[i]) return i;
   }
   return -1;
}

//BinSearch wrapper for recursive implementation(see below)
int BinSearch(uint key, uint set[], uint size)
{

      return BinSearchRec(key,set, 0, size);

}

//Binary Search - return index of key in set, or -1
int BinSearchRec(uint key, uint set[], uint beginning, uint end)
{
 

  return -1;
}
