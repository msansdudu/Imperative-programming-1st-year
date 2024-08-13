#include <stdio.h>

int main()
{
	//FILE *f = fopen("in.txt", "r");
	int a[130] = {0};
	char c;
	c = getchar();
	while (c != EOF){
		a[(int)c]++;
		c = getchar();
	}
	for (int i = 32; i <= 126; i++){
		if (a[i] > 0){
			printf("%c ", i);
			for (int j = 0; j < a[i]; j++){
				printf("#");
			}
			printf("\n");
		}
	}
	return 0;
}

