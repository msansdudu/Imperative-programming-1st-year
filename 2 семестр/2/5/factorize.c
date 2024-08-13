typedef struct Factors{
	int k;				//сколько различных простых в разложении
	int primes[32];		//различные простые в порядке возрастания
	int powers[32];		//в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res){
	int del = 2, f = 0;
	res->k = 0;
	for (int i = 0; i < 32; i++){
		res->powers[i] = 0;
	}
	while (del * del <= X){
		if (X % del == 0){
			res->primes[res->k] = del;
			f = 1;
		}
		while (X % del == 0){
			res->powers[res->k]++;
			X /= del;
		}
		del++;
		if (f){
			res->k++;;
			f = 0;
		}
		if (X <= 1) {
			break;
		}
	}
	if (X > 1){
		res->primes[res->k] = X;
		res->powers[res->k]++;
		res->k++;
	}
}
