#include <stdio.h>

int main()
{
	int n, m = 1;
	scanf("%d", &n);
	int a[100000] = {0}, b[10001] = {0};
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (a[i] > m)
			m = a[i];
		b[a[i]]++;
	}
	for (int i = 1; i < m + 1; i++)
		if (b[i] > 0)
			printf("%d: %d\n", i, b[i]);
	return 0;
}

