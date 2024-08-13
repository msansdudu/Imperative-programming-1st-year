#include <stdio.h>

int main()
{
	double treug[1001][1001];
    int q, n, k;
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                treug[i][j] = 1;
            else
                treug[i][j] = treug[i - 1][j - 1] + treug[i - 1][j];
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
		scanf("%d%d", &n, &k);
		printf("%0.10g\n", treug[n][k]);
	}
	return 0;
}

