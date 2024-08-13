#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cnt, cap;
    int *arr;
} Vertex;

typedef struct Stack{
    int vert;
    struct Stack *next;
} Stack;

Vertex vertices[100001];
int n, visited[100001] = {0}, res[100001], flag = 0;
Stack *stack = NULL;

void add(int from, int to){
    if (vertices[from].cap <= vertices[from].cnt){
        vertices[from].cap *= 2;
        vertices[from].arr = realloc(vertices[from].arr, vertices[from].cap * sizeof(int));
	}
	vertices[from].arr[(vertices[from].cnt)++] = to;
}

void top_sort(int v){
    visited[v] = 1;
    for (int i = 0; i < vertices[v].cnt; i++){
        if (visited[vertices[v].arr[i]] == 1){
            flag = 1;
            return;
        }
        if (!visited[vertices[v].arr[i]]){
            top_sort(vertices[v].arr[i]);
        }
    }
    visited[v] = 2;
    Stack *tmp = (Stack*)malloc(sizeof(Stack)); 
    tmp->vert = v; 
    tmp->next = stack;
    stack = tmp;
}

int main(){
    int m, less, bigger;
    scanf("%d%d", &n ,&m);
    for (int i = 0; i < n; i++){
        vertices[i].cnt = 0;
        vertices[i].cap = 1;
        vertices[i].arr = (int*) malloc(sizeof(int));
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d", &less, &bigger);
        add(bigger - 1, less - 1);
    }

    for (int i = 0; i < n; ++i) { 
        if (!visited[i]) { 
            top_sort(i); 
        } 
    }
    
    if (flag){
        printf("NO");
        for (int i = 0; i < n; i++){
            free(vertices[i].arr);
        }
        return 0;
    }

    int step = 0;
    while (stack != NULL){ 
        res[stack->vert] = n - (step++);
        Stack *tmp = stack;
        stack = stack->next; 
        free(tmp); 
    }
    printf("YES\n");
    for (int i = 0; i < n; i++){
        printf("%d ", res[i]);
        free(vertices[i].arr);
    }
    return 0;
}