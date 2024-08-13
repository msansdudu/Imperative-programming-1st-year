#include <stdio.h>
#include <stdlib.h>

void ext_euclid(long long a, long long b, long long *x, long long *y, long long *d){
	long long q, r, x1, y1, x2, y2;
	if (b == 0) {
		*d = a;
		*x = 1;
		*y = 0;
		return;
	}
	x1 = 0;
	x2 = 1;
	y1 = 1;
	y2 = 0;
	while (b > 0) {
		q = a / b;
		r = a - q * b;	//новый остаток
		*x = x2 - q * x1;
		*y = y2 - q * y1;
		a = b;
		b = r;
		x2 = x1;
		x1 = *x;
		y2 = y1;
		y1 = *y;
	}
	*d = a, *x = x2, *y = y2;
}


long long inverse(long long a, long long m){
	long long d, x, y;
	ext_euclid(a, m, &x, &y, &d);
	if (d == 1){
		return x;
	}
	return 0;
}


int main()
{
	int k;
	long long prod = 1, sum = 0;
	scanf("%d", &k);
	long long *mod = (long long*) malloc(sizeof(long long) * k);
	long long *rest = (long long*) malloc(sizeof(long long) * k);
	for (int i = 0; i < k; i++){
		scanf("%lld", &mod[i]);
		prod *= mod[i];
	}
	for (int i = 0; i < k; i++){
		scanf("%lld", &rest[i]);
	}
	
	long long *new_mod = (long long*) malloc(sizeof(long long) * k);
	for (int i = 0; i < k; i++){
		new_mod[i] = prod / mod[i];
	}
	
	for (int i = 0; i < k; i++){
		sum = (sum + (((rest[i] * inverse(new_mod[i] % mod[i], mod[i])) % mod[i]) * new_mod[i]) % prod) % prod;
	}
	
	printf("%lld", (sum % prod < 0) ? prod + sum % prod : sum % prod);
	return 0;
}

