#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct vertex{ 
    int vertex; 
    struct vertex *next; 
} vertex;
 
int component[100001], stack[100001], cnt = 0, top = -1; 
 
void addEdge(vertex *graph[], vertex *inv_graph[], int from, int to){ 
    vertex *tmp = (vertex*) malloc(sizeof(vertex)); 
    tmp->vertex = to;
    tmp->next = graph[from]; 
    graph[from] = tmp;

    vertex *tmp1 = (vertex*) malloc(sizeof(vertex));
    tmp1->vertex = from;
    tmp1->next = inv_graph[to];
    inv_graph[to] = tmp1;
} 
 
void dfs(int u, int *visited, vertex *graph[], int is_inv){
    if (!is_inv){
        visited[u] = 1; 
        for (vertex *tmp = graph[u]; tmp != NULL; tmp = tmp->next) { 
            if (!visited[tmp->vertex]){ 
                dfs(tmp->vertex, visited, graph, is_inv); 
            } 
        } 
        stack[++top] = u;
    }
    else {
        visited[u] = 0; 
        component[u] = cnt; 
        for (vertex *tmp = graph[u]; tmp != NULL; tmp = tmp->next){ 
            if (visited[tmp->vertex]){ 
                dfs(tmp->vertex, visited, graph, is_inv); 
            } 
        } 
    }
}
 
int main(){ 
    int n, m, from, to;
    int visited[100001] = {0};
    vertex *graph[100001], *inv_graph[100001]; 
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < n; i++){
        graph[i] = NULL;
        inv_graph[i] = NULL;
    }

    for (int i = 0; i < m; i++){ 
        scanf("%d %d", &from, &to);
        addEdge(graph, inv_graph, from - 1, to - 1); 
    } 
    for (int i = 0; i < n; i++) 
    { 
        if (!visited[i]){ 
            dfs(i, visited, graph, 0); 
        } 
    } 

    int u;
    while (top != -1){ 
        u = stack[top--]; 
        if (visited[u]){ 
            cnt++; 
            dfs(u, visited, inv_graph, 1); 
        } 
    } 
 
    printf("%d\n", cnt); 
    for (int i = 0; i < n; i++){ 
        printf("%d ", component[i]); 
    }
    return 0; 
}
