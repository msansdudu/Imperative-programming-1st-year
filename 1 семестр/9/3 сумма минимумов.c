#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}


int main()
{
	int n, *a;
	long long sum = 0;
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++){
		sum += (long long)a[i] * (n - 1 - i);
	}
	printf("%lld", sum);
	return 0;
}

