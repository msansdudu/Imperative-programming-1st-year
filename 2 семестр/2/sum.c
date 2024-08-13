#include <stdio.h>
#include <stdint.h>

long long *arr_sum;
int n;

void Init(const int *arr, int n){
	arr_sum[0] = (int64_t)arr[0];
	for (int i = 1; i < n; i++){
		arr_sum[i] = arr_sum[i - 1] + (int64_t)arr[i];
	}
}

int64_t Sum(int l, int r){
	if (l == 0){
		if (r == 0){
			return 0;
		}	
		return arr_sum[r - 1];
	}
	return arr_sum[r - 1] - arr_sum[l - 1];
}
