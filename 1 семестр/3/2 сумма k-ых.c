
#include <stdio.h>

int main()
{
	int n, j;
	scanf("%d", &n);
	int a[100001], b[100001];
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int k = 1; k < n + 1; k++){
		j = 1;
		while (j * k < n + 1){
			b[k - 1] += a[j * k - 1];
			j++;
		}
	}
	for (int i = 0; i < n; i++) printf("%d\n", b[i]);
	return 0;
}

