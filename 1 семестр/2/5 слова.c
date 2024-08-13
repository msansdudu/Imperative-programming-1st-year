#include <stdio.h>

int main()
{
	char in, pr;
	int k=0;
	scanf("%c", &in);
	
	if (in != '.' && in != '\n') k++; // проверка есть ли точки перед первым словом и не пустая ли строка
	
	while (in != '\n'){
		if (pr == '.' && in != '.') k++; // если предыдущий символ ".", а нынешний -- не ".", значит началось новое слово
		pr = in;
		scanf("%c", &in);
	}
	printf("%d", k);
	return 0;
}

