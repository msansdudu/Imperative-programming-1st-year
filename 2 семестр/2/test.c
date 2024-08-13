#include <stdio.h>

int main()
{
	printf("\n\ta\tb\tc\tres\n\n");
	for (int a = 0; a <= 1; a++){
		for (int b = 0; b <= 1; b++){
			for (int c = 0; c <= 1; c++){
				printf("\t%d\t%d\t%d\t %d\n", a, b, c, !(a && (b || c)));
			}
		}
	}
	return 0;
}

