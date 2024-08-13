# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
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
assert ( IsInSet ( sEmpty , 0) == 0 && IsInSet ( sEmpty , -123456789) == 0);
DeleteSet ( sEmpty ); // set is destroyed
IntegerSet * sNull = 0;
//null pointer must be treated by IsInSet as empty set
assert ( IsInSet ( sNull , 0) == 0 && IsInSet ( sNull , -123456789) == 0);
myarr [0] = -5;
//if array has equal elements, then CreateSet must return 0
IntegerSet * sBad = CreateSet ( myarr , 3);
assert ( sBad == 0);
int largearr [] = {1 , 5 , INT_MAX , INT_MIN , 1000000000 , -123 , 555 , 0};
//create set with 8 numbers from largearr
IntegerSet * sLarge = CreateSet ( largearr , 8);
for(int i = 0; i < sLarge->n; i++){
	printf("%d ", sLarge->arr[i]);
}
assert ( IsInSet ( sLarge , INT_MAX ) == 1 && IsInSet ( sLarge , INT_MIN ) == 1);
assert ( IsInSet ( sLarge , 1000000000) == 1 && IsInSet ( sLarge , -123) == 1);
assert ( IsInSet ( sLarge , 123) == 0 && IsInSet ( sLarge , -5) == 0);
DeleteSet ( sLarge ); // set is destroyed
largearr [1] = 5;
sLarge = CreateSet ( largearr , 8); //same set as previously
assert ( IsInSet ( sLarge , 5) == 1);
DeleteSet ( sLarge ); // set is destroyed
largearr [7] = 5;
sLarge = CreateSet ( largearr , 8); //now it has equal elements
assert ( sLarge == 0);
DeleteSet ( sLarge ); // set is destroyed
return 0;
}
