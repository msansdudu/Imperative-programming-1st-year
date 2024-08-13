#include <stdio.h>
#include <stdint.h>

int inv(int64_t n, int m){
	int deg = m - 2;
	int res = 1;
	while (deg){
		if (deg & 1){
			res = (res * n) % m;
		}
		n = (n * n) % m;
		deg >>= 1;
	}
	return res;
}


int main(int argc, char **argv)
{
	int t, m, a;
	scanf("%d%d", &t, &m);
	for (int i = 0; i < t; i++){
		scanf("%d", &a);
		if (a % m == 0){
			printf("-1\n");
		}
		else {					// надо возвести в степень m-2
			printf("%d\n", inv((int64_t)a, m));
		}
	}
	return 0;
}

