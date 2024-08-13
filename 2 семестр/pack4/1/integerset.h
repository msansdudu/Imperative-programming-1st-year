#ifndef MODULAR_H_
#define MODULAR_H_
typedef struct IntegerSet{
	int *arr;
	int n;
} IntegerSet;
IntegerSet *CreateSet(int *arr, int n);
void DeleteSet(IntegerSet *set);
int IsInSet(IntegerSet *set, int n);
#endif
