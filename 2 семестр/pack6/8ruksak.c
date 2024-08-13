#include <stdio.h>

typedef struct elem{
    int cost, weight;
} elem;

int table[210][50010];

int costs(elem item, int i, int m){
    if (m < item.weight){
        return table[i - 1][m];
    }
    if (table[i - 1][m] > table[i - 1][m - item.weight] + item.cost){
        return table[i - 1][m];
    }
    return table[i - 1][m - item.weight] + item.cost;
}

void print_res(elem *arr, int i, int j, int n, int weight, int cost) {
    if (table[i][j] == 0){
        printf("%d %d %d\n", n, weight, cost);
    }
    else if (table[i][j] == table[i - 1][j]){
        print_res(arr, i - 1, j, n, weight, cost);
    }
    else {
        print_res(arr, i - 1, j - arr[i - 1].weight, n + 1, weight + arr[i - 1].weight, cost);
        printf("%d ", i);
    }
}

int main(){
    int n, w;
    elem arr[210];
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &arr[i].weight, &arr[i].cost);
    }

    for (int i = 1; i <= n; i++){
        for (int m = 1; m <= w; m++){
            table[i][m] = costs(arr[i - 1], i, m);
        }
    }

    print_res(arr, n, w, 0, 0, table[n][w]);
    return 0;
}