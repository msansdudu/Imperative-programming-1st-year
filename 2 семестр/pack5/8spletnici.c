#include <stdio.h>
#define min(a, b) a < b ? a : b

typedef struct{
    int from, to;
} Request;

Request requests[300001];
int graph[3001][3001], dist[3001][3001], next[3001][3001];

int min_id(int n, int visited[], int cur){
    int min = 300000000, min_id;
    for (int i = 0; i < n; i++){
        if (visited[i] == 0 && dist[cur][i] <= min){
            min = dist[cur][i];
            min_id = i;
        }
    }
    return min_id;
}

void dijkstra(int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = i == j ? 0 : 300000000;
            next[i][j] = i == j ? j : 0;
        }
    }
    for (int i = 0; i < n; i++){
        int visited[3001] = {0};
        for (int j = 0; j < n - 1; j++){
            int u = min_id(n, visited, i);
            visited[u] = 1;

            for (int v = 0; v < n; v++){
                if (!visited[v] && graph[u][v] != 300000000 && dist[i][u] != 300000000 && dist[i][u] + graph[u][v] < dist[i][v]){
                    dist[i][v] = dist[i][u] + graph[u][v];
                    next[i][v] = u;
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

int main(){
    int n, m, k, from, to, weight, cnt = 0, path[3010];
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++){
        scanf("%d%d", &from, &to);
        requests[i].from = from - 1;
        requests[i].to = to - 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            graph[i][j] = 300000000;
        }
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &from, &to, &weight);
        graph[from - 1][to - 1] = min(graph[from - 1][to - 1], weight);
        graph[to - 1][from - 1] = graph[from - 1][to - 1];
    }

    dijkstra(n, m);
    
    for (int i = 0; i < k; i++){
        from = requests[i].from;
        to = requests[i].to;
 //       cnt = find_path(path, from, to);
        if (dist[from][to] == 300000000){
            printf("NO\n");
            continue;
        }
        printf("YES %d %d", dist[from][to], cnt);
        for (int j = 0; j < cnt; j++){
            printf(" %d", path[j] + 1);
        }
        printf("\n");
    }
    return 0;
}