#include <stdio.h>

void f(char c, char *s, int *up, int *len)
{
	s[*len] = c;
	if (c >= 'A' && c <= 'Z'){
		*up += 1;
	}
	*len += 1;
}

int main()
{
	char c, s[1000001] = "adfb";
	int up = 0, len = 0;
	scanf("%c", &c);
	while (c != '\0' && c != '\n'){
		if (c == '.' || c == ',' || c == ';' || c == ':'){
			if (len != 0){
				s[len] = '\0';
				printf("%d/%d %s\n", up, len, s);
				len = 0;
				up = 0;
			}
		}
		else {
			f(c, s, &up, &len);
		}
		scanf("%c", &c);
	}
	if (len != 0){
		s[len] = '\0';
		printf("%d/%d %s", up, len, s);
	}
	return 0;
}

