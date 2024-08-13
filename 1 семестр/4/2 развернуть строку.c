#include <stdio.h>
#include <string.h>

void reverse(char *start, int len){
	char tmp;
	for (int j = 0; j < len / 2; j++){
		tmp = start[len - j - 1];
		start[len - j - 1] = start[j];
		start[j] = tmp;
	}
}

int main()
{
	int n;
	char s[110];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s);
		reverse(s, strlen(s));
		printf("%s\n", s);
	}
	return 0;
}

