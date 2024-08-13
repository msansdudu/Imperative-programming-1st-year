#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Init(const int *arr, int n);
int64_t Sum(int l, int r);
int Query(int l, int64_t sum);

long long *arr_sum;
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, l, s, *arr;
	scanf("%d%d", &n, &m);
	arr = (int*) malloc(sizeof(int) * n);
	arr_sum = (long long*) malloc(sizeof(long long) * n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	Init(&arr[0], n);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &l, &s);
		printf("%d\n", Query(l, s));
	}
	free(arr);
	free(arr_sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

