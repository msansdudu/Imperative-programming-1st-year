#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 1){
		fprintf(stderr, "No parameters specified.");
		return 13;
	}
	if (argc == 4){
		long long a = atoi(argv[2]), b = atoi(argv[3]);
		if (!strcmp(argv[1], "sub")){
			printf("%lld", a - b);
		}
		else if (!strcmp(argv[1], "add")){
			printf("%lld", a + b);
		}
		else if (!strcmp(argv[1], "mul")){
			printf("%lld", a * b);
		}
	}
	else {
		int m;
		long long a, b;
		if (!strcmp(argv[1], "-m")){
			m = atoi(argv[2]);
			a = atoi(argv[4]);
			b = atoi(argv[5]);
		}
		else {
			m = atoi(argv[5]);
			a = atoi(argv[2]);
			b = atoi(argv[3]);
		}

		if (!strcmp(argv[1], "sub") || !strcmp(argv[3], "sub")){
			printf("%lld", ((a - b) % m >= 0) ? (a - b) % m : m + ((a - b) % m));
		}
		else if (!strcmp(argv[1], "add") || !strcmp(argv[3], "add")){
			printf("%lld", ((a + b) % m >= 0) ? (a + b) % m : m + ((a + b) % m));
		}
		else if (!strcmp(argv[1], "mul") || !strcmp(argv[3], "mul")){
			printf("%lld", ((a * b) % m >= 0) ? (a * b) % m : m + ((a * b) % m));
		}
	}
	return 0;
}

