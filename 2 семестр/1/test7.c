#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int sys[201][202], ko;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n + 1; j++){
			scanf("%d", &sys[i][j]);		//считываем систему
		}
	}
	
	
	for (int i = 0; i < n - 1; i++){
		int k = i;
		for (; sys[k][i] == 0; k++);	//исключаем 0 первым коэффициентом
		if (k != i){
			int tmp;
			for (int j = 0; j < n + 1; j++){
				tmp = sys[i][j];
				sys[i][j] = sys[k][j];
				sys[k][j] = tmp;
			}
		}
		for (int j = i + 1; j < n; j++){			
			ko = sys[j][i] / sys[i][i];
			for (int k = i; k < n + 1; k++){
				sys[j][k] -= sys[i][k] * ko;		//приводим к ступенчатому виду
			}
		}
	}
	
	int res[201] = {0};
	res[n - 1] = sys[n - 1][n] / sys[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--){				//решаем
		res[i] = sys[i][n];
		for (int j = n - 1; j > i; j--){
			res[i] -= res[j] * sys[i][j];
		}
		res[i] /= sys[i][i];
	}
	
	for (int i = 0; i < n; i++){
		printf("%d\n", (res[i] % m >= 0) ? res[i] % m : m + (res[i] % m));
	}
	return 0;
}

