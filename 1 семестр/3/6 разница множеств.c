#include <stdio.h>

int main()
{
	int n, m, k, d = 0, a[100001] = {0}, max = 0;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &k);
		if (!a[k])
			d++;
		a[k] = 1;
		if (k > max) max = k;
	}
		
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &k);
		if (a[k])
			d--;
		a[k] = 0;
	}
	
	printf("%d\n", d);
	for (int i = 0; i < max + 1; i++)
		if (a[i])
			printf("%d ", i);
	return 0;
}

