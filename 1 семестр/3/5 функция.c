#include <stdio.h>

int main()
{
	int n, m, a, b, arg[310] = {0}, def[310] = {0};
	int r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 0;
	scanf("%d%d", &n, &m);
	
	
	for (int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);	
		arg[a]++;
		def[b]++;
		if (arg[a] > 1)
			r1 = 0; // если хоть для одного аргумента более одного значения, то отношение -- не функция
		if (def[b] > 1)
			r3 = 0; // если хоть для одного значения более одного аргумента, то отношение не инъективно
	}
	
	
	for (int i = 1; i < n + 1; i++){
		if (arg[i] == 0)
			r2 = 0; // не для всех аргументов нашлись значения-- не всюду определена
		if (def[i] == 0)
			r4 = 0; // не для всех значений нашлись аргументы -- не сюръективна
	}
	if (!r1){		// если не функция -- остальные свойства недействительны
		r2 = 0;
		r3 = 0;
		r4 = 0;
		r5 = 0;
	}
	else if (r3 && r4)
			r5 = 1; // если 3 и 4 выполняются, то 5 тоже
	
	
	if (r1)
		printf("1 ");
	if (r2)
		printf("2 ");
	if (r3)
		printf("3 ");
	if (r4)
		printf("4 ");
	if (r5)
		printf("5 ");
	if (!(r1 + r2 + r3 + r4 + r5)) // если ничего из свойств -- выводим 0
		printf("0");
	return 0;
}

