#include "sort.h"
#include <stdio.h>
#include <time.h>

//Do a sort, but time it.  Both prints and returns time in msec CPU.
void TimeSort(void (*fctn)(uint*,uint), uint set[], uint size)
{
  clock_t diff = 0;
  clock_t start = clock();
  fctn(set,size); //Sort
  diff = clock() - start;
  printf("Sort completed in %lu msec.\n", diff*1000/CLOCKS_PER_SEC);
}

//Bubble sort(ewww!)
/*source code from here:
http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
*/
void BubSort(uint set[], uint size)
{
    for (int b = 0; b < size; b++)
    {
      for (int u = 0; u < (size - b - 1); u++)
      {
        if (set[u] > set[u+1])
        {
          int bubswap = set[u];
          set[u]      = set [u+1];
          set[u+1]    = bubswap;
        }
      }
    }
}

//Selection sort
/* source code from here:
http://www.programmingsimplified.com/c/source-code/c-program-selection-sort
*/
void SelSort(uint set[], uint size)
{
  for (int s = 0; s < size; s++)
  {
    int selpos = s;

    for (int o = s+1; o < size; o++)
    {
      if (set[selpos] > set[o])
          selpos = o;
    }
    if (selpos != s)
    {
        int selswap = set[s];
        set[s] = set[selpos];
        set[selpos] = selswap;
    }
  }
}
