#include <stdio.h>
#include <stdlib.h>

typedef struct IntegerSet{
	int *arr;
	int n;
} IntegerSet;


IntegerSet *CreateSet(int *arr, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {  
			if(arr[j] > arr[j + 1]){
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp; 
			}
		}
	}
	IntegerSet *set = (IntegerSet*) malloc(sizeof(IntegerSet));
	set->arr = (int*) malloc(n * sizeof(int));
	set->n = n;
	for (int i = 0; i < n; i++){
		set->arr[i] = arr[i];
		if (i != 0 && arr[i - 1] == arr[i]){
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
