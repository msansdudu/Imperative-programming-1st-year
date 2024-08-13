#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
	int n, p, q;
	double x;
	long long a, b;
	int64_t m;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++){
		scanf("%d/%d xor %llx", &p, &q, &m);
		x = (double)p / (double)q;
		memcpy(&b, &x, sizeof(double));
		memcpy(&a, &m, sizeof(int64_t));
		printf("%0.15g\n", a ^ b);
	}
	return 0;
}

