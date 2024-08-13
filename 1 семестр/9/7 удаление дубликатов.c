#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}


int main()
{
	int n, *a, count = 1, *b;
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp);
	b[0] = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] != a[i - 1]){
			b[count] = a[i];
			count++;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++){
		printf("%d\n", b[i]);
	}
	return 0;
}

