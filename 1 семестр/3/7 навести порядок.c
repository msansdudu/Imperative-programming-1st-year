#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int tmp, f;
	for (int i = n - 1; i >= 0; i--){
		f = 1;
		for (int j = 0; j < i; j++){
			if (a[j] > a[j + 1]){
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				f = 0;
			}
		}
		if (f) break;
	}
	
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}

