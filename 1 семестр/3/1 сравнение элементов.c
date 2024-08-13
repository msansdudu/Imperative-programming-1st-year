
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[101], b[101];
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[i]){
				b[i]++;
			}
		}
		printf("%d ", b[i]);
	}
	printf("%d", b[n - 1]);
	return 0;
}

