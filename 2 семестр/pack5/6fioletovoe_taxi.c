#include <stdio.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int dist[310][310], next[310][310];

void floyd_warshall(int n, int m){
    int from, to, weight;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[i][j] = i == j ? 0 : 300000000;
            next[i][j] = i == j ? j : 0;
        }
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &from, &to, &weight);
        dist[from][to] = min(dist[from][to], weight);
        dist[to][from] = dist[from][to];
        next[from][to] = to;
        next[to][from] = from;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

int find_path(int *path, int from, int to){
    int cnt = 0;
    if (next[from][to] == 0){
        return 0;
    }
    path[cnt++] = from;
    while (from != to){
        from = next[from][to];
        path[cnt++] = from;
    }
    return cnt;
}

// считаем вершины реально с единицы
int main(){
    int n, m, p, k, from, to, path[310], cnt = 0;
    scanf("%d%d%d%d", &n, &m, &p, &k);
    
    floyd_warshall(n, m);

    for (int i = 0; i < p; i++){                // ищем кратчайший путь детально
        scanf("%d%d", &from, &to);
        printf("%d", dist[from][to]);
        cnt = find_path(path, from, to);
        printf(" %d", cnt);
        for (int j = 0; j < cnt; j++){
            printf(" %d", path[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < k; i++){                // ищем длину кратчайшего пути
        scanf("%d%d", &from, &to);
        printf("%d\n", dist[from][to]);
    }
    return 0;
}