#include <stdio.h>
#include <stdint.h>

void Init(const int *arr, int n);
int64_t Sum(int l, int r);

long long *arr_sum;
int n;

int Query(int l, int64_t sum){
	int left = l, right = n, mid = n;
	while (right - left > 1){
		mid = (left + right) / 2;
		if (Sum(l, mid) > sum){
			right = mid;
		}
		else if (Sum(l, mid) < sum){
			left = mid;
		}
		else {
			break;
		}
	}
	if (Sum(l, mid) > sum){
		while (Sum(l, mid) > sum && mid > 0){
			mid--;
		}
		return mid;
	}
	while (Sum(l, mid) <= sum && mid <= n - 1){
		mid++;
	}
	if (Sum(l, mid) > sum){
		mid--;
	}
	return mid;
}
