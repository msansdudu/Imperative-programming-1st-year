#include <stdio.h>

int main()
{
	int n, l = 0, r = 0, sum, sum1, a[5000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sum = a[0];
	for (int i = 0; i < n; i++){
		sum1 = 0;
		for (int j = i; j < n; j++){
			sum1 += a[j];
			if (sum1 > sum){
				l = i;
				r = j;
				sum = sum1;
			}
		}
	}		
	
	printf("%d %d %d", l, r, sum);	
	return 0;
}

