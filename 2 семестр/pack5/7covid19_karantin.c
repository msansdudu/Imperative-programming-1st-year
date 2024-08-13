#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int from, to, weight;
} Edge;

typedef struct path{
    int vert;
    struct path *next;
} path;

int friends[51], dist[5010], pred[5010];
Edge edges[50010];

void bellman_ford(int src, int n, int m, int MAX){
    for (int i = 0; i < n; i++){
        dist[i] = MAX;
        pred[i] = -1;
    }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            if (dist[edges[j].from] != MAX && dist[edges[j].from] + edges[j].weight < dist[edges[j].to]){
                dist[edges[j].to] = dist[edges[j].from] + edges[j].weight;
                pred[edges[j].to] = edges[j].from;
            }
        }
    }
}

// номера всех вершин уменьшены на 1, счет с 0
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int src = 0, v, from, to, weight;    
    for (int i = 0; i < k; i++){
        scanf("%d", &v);
        friends[i] = v - 1;
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &from, &to, &weight);
        edges[i].from = from - 1;
        edges[i].to = to - 1;
        edges[i].weight = weight;
    }

    bellman_ford(src, n, m, 2147483640);

    for(int i = 0; i < k; i++){
        printf("%d", dist[friends[i]]);
        int p = pred[friends[i]], cnt = 1;
        path *first = (path*) malloc(sizeof(path));
        first->vert = friends[i] + 1;
        first->next = NULL;
        while (p != -1){
            path *tmp = (path*) malloc(sizeof(path));
            tmp->vert = p + 1;
            tmp->next = first;
            first = tmp;
            p = pred[p];
            cnt++;
        }
        printf(" %d", cnt);
        while (first != NULL){
            path *tmp = first;
            printf(" %d", tmp->vert);
            first = first->next;
            free(tmp);
        }
        printf("\n");
    }
    return 0;
}