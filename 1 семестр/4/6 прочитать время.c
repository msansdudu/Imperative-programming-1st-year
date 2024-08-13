#include <stdio.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds)
{
	int kol, h = 0, m = 0, s = 0;
	kol = sscanf(iStr, "%d:%d:%d", &h, &m, &s);
	if (kol == 0 || iStr[1] == '|' || h > 23 || m > 59 || s > 59){
		return 0;
	}
	*oHours = h;
	*oMinutes = m;
	*oSeconds = s;
	return 1;
}

int main()
{
	char s1[15];
	int res, h = -1, m = -1, s = -1;
	scanf("%s", s1);
	res = readTime(s1, &h, &m, &s);
	printf("%d %d %d %d\n", res, h, m, s);
	printf("%d %d %d\n", res, h, m);
	printf("%d %d", res, h);
	return 0;
}

