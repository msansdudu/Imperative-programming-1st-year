#include <stdio.h>
#include <string.h>

char* concat (char *pref, char *suff){
	int i, len = strlen(pref);
	for (i = len; suff[i - len] != '\0'; i++){
		pref[i] = suff[i - len];
	}
	pref[i] = '\0';
	return &pref[i];
}

int main(int argc, char **argv)
{
	int n;
	char c[110], a[10000010], *p;
	scanf("%d", &n);
	scanf("%s", a);
	for (p = a; p[0] != '\0'; p++);
	for (int i = 0; i < n - 1; i++){
		scanf("%s", c);
		p = concat(p, c);
	}
	printf("%s", a);
	return 0;
}
