# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include <limits.h>
#include <string.h>


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


int main () {
int myarr [] = {1 , 2 , 3};
//create set with numbers 1, 2, and 3
IntegerSet * s123 = CreateSet ( myarr , 3);
myarr [1] = -5;
assert ( IsInSet ( s123 , 3) == 1 && IsInSet ( s123 , 2) == 1);
assert ( IsInSet ( s123 , 0) == 0 && IsInSet ( s123 , 4) == 0);
DeleteSet ( s123 ); // set is destroyed, all used resources should be released
//create set with numbers -5 and 3
IntegerSet * s15 = CreateSet ( myarr + 1, 2);
assert ( IsInSet ( s15 , 3) == 1 && IsInSet ( s15 , -5) == 1);
assert ( IsInSet ( s15 , 1) == 0 && IsInSet ( s15 , 2) == 0);
DeleteSet ( s15 ); // set is destroyed
//create empty set (note: null pointer is allowed only when size is 0)
IntegerSet * sEmpty = CreateSet (0 , 0);
assert ( sEmpty != 0);
assert ( IsInSet ( sEmpty , 0) == 0 && IsInSet ( sEmpty , -12345678) == 0);
DeleteSet ( sEmpty ); // set is destroyed
IntegerSet * sNull = 0;
//null pointer must be treated by IsInSet as empty set
assert ( IsInSet ( sNull , 0) == 0 && IsInSet ( sNull , -12345678) == 0);
myarr [0] = -5;
//if array has equal elements, then CreateSet must return 0
IntegerSet * sBad = CreateSet ( myarr , 3);
assert ( sBad == 0);

return 0;
}
