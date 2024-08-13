#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cnt, cap;
    int *arr;
} vertex;

typedef struct vert{
    int vert;
    struct vert *next;
} Vert;

vertex vertices[200010];
Vert *first = NULL;
int visited[200010] = {0}, flag = 0, beg = -1, cnt = 0;

void dfs(int v){
    visited[v] = 1;
    for (int i = 0; i < vertices[v].cnt; i++){
        if (flag != 0){
            break;
        }
        if (visited[vertices[v].arr[i]] == 1){
            beg = vertices[v].arr[i];
            Vert *tmp = (Vert*) malloc(sizeof(Vert));
            tmp->next = first;
            tmp->vert = beg;
            first = tmp;
            flag = 1;
            cnt++;
            break;
        }
        if (!visited[vertices[v].arr[i]]){
            dfs(vertices[v].arr[i]);
        }
    }
    visited[v] = 2;
    if (v == beg){
        flag = 2;
        return;
    }
    if (flag == 1){
        Vert *tmp = (Vert*) malloc(sizeof(Vert));
        tmp->next = first;
        tmp->vert = v; 
        first = tmp;
        cnt++;
    }
}

void add(int from, int to){
    if (vertices[from].cap <= vertices[from].cnt){
        vertices[from].cap *= 2;
        vertices[from].arr = realloc(vertices[from].arr, vertices[from].cap * sizeof(int));
	}
	vertices[from].arr[(vertices[from].cnt)++] = to;
}

int main(){
    int n, m, from, to;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        vertices[i].cnt = 0;
        vertices[i].cap = 1;
        vertices[i].arr = (int*) malloc(sizeof(int));
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d", &from, &to);
        add(from - 1, to - 1);
    }

    int v = 0;
    while (v != n){
        if (flag != 0){
            break;
        }
        if (visited[v] == 0){
            dfs(v);
        }
        v++;
    }
    
    if (flag == 0){
        printf("-1");
        return 0;
    }
    printf("%d\n", cnt);
    while (first != NULL){
        Vert *tmp = first;
        printf("%d ", tmp->vert + 1);
        first = first->next;
        free(tmp);
    }

    for (int i = 0; i < n; i++){
        free(vertices[i].arr);
    }
    return 0;
}