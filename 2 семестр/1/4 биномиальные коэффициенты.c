#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long **treug = (long long**) malloc(sizeof(long long*) * 2001);
	for (int i = 0; i < 2001; i++){
		treug[i] = (long long*) malloc(sizeof(long long) * 2001);
	}
    int t, m, n, k;
    scanf("%d%d", &m, &t);
    for (int i = 0; i < 2001; i++){
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                treug[i][j] = 1;
            else
                treug[i][j] = (treug[i - 1][j - 1] + treug[i - 1][j]) % m;
        }
    }
    for (int i = 0; i < t; i++){
		scanf("%d%d", &n, &k);
		if (k < 0 || k > n){
			printf("0\n");
		}
		else {
			printf("%lld\n", treug[n][k]);
		}
	}
	for (int i = 0; i < 2001; i++){
		free(treug[i]);
	}
	free(treug);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
