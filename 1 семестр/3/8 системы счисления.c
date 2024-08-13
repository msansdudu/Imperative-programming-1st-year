#include <stdio.h>

int main()
{
	int p, q, d = 0, st = 1, n = 0;
	char s[30], s1[30];
	scanf("%d %d %s", &p, &q, s);
	
	while (s[n] != '\0')
		n++; // нашли длину строки
	
	for (int i = n - 1; i > -1; i--){
		if (s[i] - '0' <= 9)
			d += (s[i] - '0') * st; // перевели в десятичную систему
		else
			d += (s[i] + 10 - 'a') * st;
		st *= p;
	}

	
	n = 0;
	while (d > 0){
		if (d % q < 10)
			s1[n] = d % q + '0';
		else
			s1[n] = d % q - 10 + 'a';
		n++;
		d /= q;
	}
	
	for (int i = n - 1; i > -1; i--){
		printf("%c", s1[i]);
	}
	return 0;
}

