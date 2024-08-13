
#include <stdio.h>

int main()
{
	int n, b, k, d = 1;
	scanf("%d\n", &n);
	char s;
	for (int i = 0; i < n; i++){
		scanf("%c", &s);
		b = s - '0'; // из кода символа цифры отнимает код символа нуля, получаем саму цифру
		if (i % 8 == 0){
			k = 0;
			d = 1;
		}
		k += b * d;
		d *= 2;
		if (i % 8 == 7 || i == n - 1) printf("%d ", k);
	}
	return 0;
}

