#include <stdio.h>
#define min(a, b) a < b ? a : b

int graph[102][102];
int visited[102] = {0};
int n;

int dfs(int v, int end, int *min_value) {
    visited[v] = 1;
    if (v == end) {
        return 1;
    }
    for (int u = 1; u <= n; u++) {
        if (!visited[u] && graph[v][u] > 0){
            *min_value = min(*min_value, graph[v][u]);
            if (dfs(u, end, min_value)){
                graph[v][u] -= *min_value;
                graph[u][v] += *min_value;
                return 1;
            }
        }
    }
    return 0;
}

int FordFulkerson(int v, int end) {
    int maxFlow = 0, min_value;
    while (1) {
        min_value = 10000000;
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }
        if (!dfs(v, end, &min_value)) {
            break;
        }
        maxFlow += min_value;
    }
    return maxFlow;
}

int main() {
    int k, from, to, c;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &from, &to, &c);
        graph[from][to] = c;
        graph[to][from] = c;
    }
    printf("%d", FordFulkerson(1, n));
    return 0;
}
