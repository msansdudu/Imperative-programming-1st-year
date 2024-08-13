#include <stdio.h>

typedef struct Factors{
	int k;				//сколько различных простых в разложении
	int primes[32];		//различные простые в порядке возрастания
	int powers[32];		//в какие степени надо эти простые возводить
} Factors;

//функция, которая находит разложение числа X и записывает его в структуру res
void Factorize(int X, Factors *res);


int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, X;
	Factors res;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &X);
		if (X == 1){
			printf("1 = 1\n");
		}
		else {
			Factorize(X, &res);
			printf("%d = %d^%d", X, res.primes[0], res.powers[0]);
			for (int i = 1; i < res.k; i++){
				printf(" * %d^%d", res.primes[i], res.powers[i]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
