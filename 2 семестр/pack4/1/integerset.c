#include <stdio.h>
#include <stdlib.h>
#include "integerset.h"

typedef struct IntegerSet{
	int *arr;
	int n;
} IntegerSet;

static int compare(const void *x1, const void *x2){
	return(*(int*)x1 - *(int*)x2);
}


IntegerSet *CreateSet(int *arr, int n){
    int *arr_copy = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr_copy[i] = arr[i];
    }
	qsort(arr_copy, n, sizeof(int), compare);
	IntegerSet *set = (IntegerSet*) malloc(sizeof(IntegerSet));
	set->arr = (int*) malloc(n * sizeof(int));
	set->n = n;
	for (int i = 0; i < n; i++){
		set->arr[i] = arr_copy[i];
		if (i != 0 && arr_copy[i - 1] == arr_copy[i]){
			return 0;
		}
	}
	return set;
}


void DeleteSet(IntegerSet *set){
	free(set->arr);
	free(set);
}


int IsInSet(IntegerSet *set, int n){
	if (set == 0){
		return 0;
	}
	int l = 0, r = set->n - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (n < set->arr[mid])
			r = mid - 1;
		else if (n > set->arr[mid])
			l = mid + 1;
		else
			return 1;
    }
    return 0;
}
