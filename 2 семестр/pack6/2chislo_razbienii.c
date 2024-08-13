#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int **res = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++){
        res[i] = (int*) malloc((n + 1) * sizeof(int));
    }
    for (int sum = n; sum >= 0; sum--){
        for (int last = 0; last <= n; last++){
            if (sum == n){
                res[sum][last] = 1;
            }
            else{
                res[sum][last] = 0;
                int m = last < (n - sum) ? last : (n - sum);
                for (int x = 1; x <= m; x++){
                    res[sum][last] = (res[sum][last] + res[sum + x][x]) % 1000000007;
                }
            }
        }
    }
    printf("%d", res[0][n]);
    for (int i = 0; i <= n; i++){
        free(res[i]);
    }
    free(res);
    return 0;
}