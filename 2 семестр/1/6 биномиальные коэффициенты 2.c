#include <stdio.h>
#include <stdint.h>


int64_t inv(int64_t n, int m){
	int deg = m - 2;
	int64_t res = 1;
	while (deg){
		if (deg & 1){
			res = (res * n) % m;
		}
		n = (n * n) % m;
		deg >>= 1;
	}
	return res;
}


int main()
{
	long long fact[1000001] = {1};
	int t, n, k, m = 1000000007;
	scanf("%d", &t);
	for (int i = 1; i < 1000001; i++){
		fact[i] = (int) (((long long) fact[i - 1] * i) % m);
	}
	for (int i = 0; i < t; i++){
		scanf("%d%d", &n, &k);
		long long res = (((fact[n] * inv(fact[k], m)) % m) * inv(fact[n - k], m)) % m;
		printf("%lld\n", res);
	}
	return 0;
}

