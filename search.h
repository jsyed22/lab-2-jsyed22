#ifndef SEARCHH
#define SEARCHH
typedef unsigned int uint;

//Do a search, but time it.
int TimeSearch(int (*fctn)(uint, uint *, uint),uint key,uint set[],uint size);

//Linear Search - return index of key in set, or -1
int SeqSearch(uint key, uint set[], uint size);

//Binary Search - return index of key in set, or -1
//Just a wrapper for the recursive one below
int BinSearch(uint key, uint set[], uint size);

//Recursive Binary search (does the real work)
int BinSearchRec(uint key, uint set[], uint beginning, uint end);
#endif
