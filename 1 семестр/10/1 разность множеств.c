#include <stdio.h>
#include <stdlib.h>


int compare(const void *x1, const void *x2){
	return (*(int*)x1 - *(int*)x2);
}


int main()
{
	int n, m, *a, *b, *res;
	scanf("%d", &n);
	a = (int*) malloc(n * sizeof(int));
	res = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	b = (int*) malloc(m * sizeof(int));
	for (int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	qsort(a, n, sizeof(int), compare);
	qsort(b, m, sizeof(int), compare);
	
	int cur_b = 0, count = 0;
	for (int i = 0; i < n; i++){
		while (b[cur_b] < a[i] && cur_b < m){
			cur_b++;
		}
		if ((b[cur_b] != a[i] && a[i] != a[i - 1] && i > 0) || (b[cur_b] != a[i] && i == 0)){
			res[count] = a[i];
			count++;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++){
		printf("%d ", res[i]);
	}
	return 0;
}

