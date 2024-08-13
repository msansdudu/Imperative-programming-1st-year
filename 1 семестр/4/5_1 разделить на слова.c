#include <stdio.h>

int f(char *s1, int len){
	int up = 0;
	for (int i = 0; i < len; i++){
		if (s1[i] >= 'A' && s1[i] <= 'Z'){
			up++;
		}
	}
	return up;
}

int main()
{
	char s[1000000], s1[1000000];
	scanf("%s", s);
	int i = 0, j = 0, up;
	while (s[i] != '\0' && s[i] != '\n'){
		if (s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == ':'){
			if (j != 0){
				s1[j] = '\0';
				up = f(s1, j);
				printf("%d/%d %s\n", up, j, s1);
				j = 0;
				s1[j] = '\0';
			}
		} else {
			s1[j] = s[i];
			j++;
		}
		i++;
	}
	if (j != 0){
		s1[j] = '\0';
		up = f(s1, j);
		printf("%d/%d %s", up, j, s1);
	}
		
	return 0;
}

