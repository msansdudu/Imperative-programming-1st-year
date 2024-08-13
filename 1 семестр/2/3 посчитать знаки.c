#include <stdio.h>

int main()
{
	double l = 0, z = 0, b = 0, sum;
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &k);
		if (k < 0) l++;
		else if(k == 0) z++;
		else b++;
	}
	sum = l + z + b;
	printf("%0.5lf %0.5lf %0.5lf", l/sum, z/sum, b/sum);
	return 0;
}

