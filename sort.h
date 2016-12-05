#ifndef SORTH
#define SORTH

typedef unsigned int uint;

//Do a sort, but time it
void TimeSort(void (*fctn)(uint*,uint), uint set[], uint size);

//Bubble sort(ewww!)
void BubSort(uint set[], uint size);

//Selection sort
void SelSort(uint set[], uint size);

#endif
