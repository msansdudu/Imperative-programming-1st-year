#include <stdio.h>
#include <string.h> /*для сравнения строк, функция strcmp(s1,s2), если
строки совпадают, возвращается 0, если первый несовпадающий символ
первой строки идет в лексикографическом порядке до символа второй
строки, то возвращается число меньше 0, иначе больше 0*/

int main()
{
	int a;
	char s[3];
	gets(s); //строки через scanf не считать
	if (!strcmp(s,"Mon")){
		a=1;
	} else if (!strcmp(s,"Tue")){
		a=2;
	} else if (!strcmp(s,"Wed")){
		a=3;
	} else if (!strcmp(s,"Thu")){
		a=4;
	} else if (!strcmp(s,"Fri")){
		a=5;
	} else if (!strcmp(s,"Sat")){
		a=6;
	} else if (!strcmp(s,"Sun")){
		a=7;
	}
	printf("%d", a);
	return 0;
}

