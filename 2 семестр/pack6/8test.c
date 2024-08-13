#include "stdio.h"
#include "stdlib.h"

typedef struct Item {
    int weight;
    int cost;
} item;


void res(int **table, item *all, int i, int j, int n, int weight, int cost) {
    if (table[i][j] == 0) {
        printf("%d %d %d\n", n, weight, cost);
        return;
    } else {
        if (table[i][j] == table[i - 1][j]) {
            res(table, all, i - 1, j, n, weight, cost);
        } else {
            res(table, all, i - 1, j - all[i - 1].weight, n + 1, weight + all[i - 1].weight, cost);
            printf("%d ", i);
        }
        return;
    }
}

int func(int **table, item a, int i, int m) {
    int end = 0;
    if (m < a.weight) {
        return table[i - 1][m];
    } else {
        if (table[i - 1][m] > table[i - 1][m - a.weight] + a.cost)
            end = table[i - 1][m];
        else
            end = table[i - 1][m - a.weight] + a.cost;
        return end;
    }
}

int main() {
    int num, max_weight, **table;
    item *all;
    scanf("%d %d", &num, &max_weight);
    all = (item *) malloc(sizeof(item) * num);
    table = (int **) malloc((num + 1) * sizeof(int *));
    table[0] = (int *) calloc(max_weight + 1, sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &all[i].weight, &all[i].cost);
        table[i + 1] = (int *) calloc(max_weight + 1, sizeof(int));
    }
    for (int i = 1; i <= num; i++) {
        for (int m = 1; m <= max_weight; m++) {
            table[i][m] = func(table, all[i - 1], i, m);
        }
    }
    res(table, all, num, max_weight, 0, 0, table[num][max_weight]);
    free(all);
    free(*table);
    free(table);
    return 0;
}
