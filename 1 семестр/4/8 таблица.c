#include <stdio.h>


int len(int n){
	int len = 0;
	while (n > 0){
		len++;
		n /= 10;
	}
	return len;
}


int main()
{
	int n, id, du, res[1001] = {0}, kol[1001] = {0};
	int m1 = 0, m2 = 0, m3 = 0;				// находим максимальные длины чисел
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &id, &du);
		res[id] += du;
		kol[id]++;
		m1 = len(id) > m1 ? len(id) : m1;
		m2 = len(kol[id]) > m2 ? len(kol[id]) : m2;
		m3 = len(res[id]) > m3 ? len(res[id]) : m3;
	}
	
	printf("+");
	for (int i = 0; i < m1 + 2; i++){
		printf("-");
	}
	printf("+");
	for (int i = 0; i < m2 + 2; i++){
		printf("-");
	}
	printf("+");
	for (int i = 0; i < m3 + 2; i++){
		printf("-");
	}
	printf("+\n");
	
	for (int i = 0; i < 1001; i++){
		if (res[i]){
			printf("|");
			for (int j = 0; j <= m1 - len(i); j++){
				printf(" ");
			}
			printf("%d |", i);
			for (int j = 0; j <= m2 - len(kol[i]); j++){
				printf(" ");
			}
			printf("%d |", kol[i]);
			for (int j = 0; j <= m3 - len(res[i]); j++){
				printf(" ");
			}
			printf("%d |\n", res[i]);		
		
// печатаем горизонтальный разделитель
			printf("+");
			for (int j = 0; j < m1 + 2; j++){
				printf("-");
			}
			printf("+");
			for (int j = 0; j < m2 + 2; j++){
				printf("-");
			}
			printf("+");
			for (int j = 0; j < m3 + 2; j++){
				printf("-");
			}
			printf("+\n");
		}
	}
	return 0;
}

