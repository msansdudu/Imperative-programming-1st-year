#include <stdio.h>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}


int main()
{
	int t, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}

