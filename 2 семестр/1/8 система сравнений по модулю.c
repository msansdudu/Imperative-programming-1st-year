#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k, p, **sys;
	scanf("%d%d%d", &n, &k, &p);
	sys = (int**) malloc(sizeof(int*) * k);
	*sys = (int*) malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < k; i++){
		for (int j = 0; j < n + 1; j++){
			scanf("%d", &sys[i][j]);
		}
	}
	return 0;
}

