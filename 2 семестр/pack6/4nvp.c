#include <stdio.h>

int main(){
    int n, seq[5001][2], pred[5001], id_max = 0, value_max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        pred[i] = -1;
        scanf("%d", &seq[i][0]);
        seq[i][1] = 1;
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (seq[i][0] < seq[j][0] && seq[j][1] <= seq[i][1]){
                seq[j][1] = 1 + seq[i][1];
                pred[j] = i;
            }
            if (value_max < seq[j][1]){
                value_max = seq[j][1];
                id_max = j;
            }
        }
    }
    printf("%d\n", value_max);
    int cnt = 0, num_seq[5001];
    while (id_max != -1){
        num_seq[cnt++] = id_max;
        id_max = pred[id_max];
    }
    for (int i = cnt - 1; i >= 0; i--){
        printf("A[%d] = %d\n", num_seq[i] + 1, seq[num_seq[i]][0]);
    }
    return 0;
}