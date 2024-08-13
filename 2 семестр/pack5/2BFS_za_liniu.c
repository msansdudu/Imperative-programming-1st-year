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

typedef struct Queue{
    Vert *front;
    Vert *rear;
} Queue;

int n, dist[200001];
vertex vertices[200001];

void add(int from, int to){
    if (vertices[from].cap <= vertices[from].cnt){
        vertices[from].cap *= 2;
        vertices[from].arr = realloc(vertices[from].arr, vertices[from].cap * sizeof(int));
	}
	vertices[from].arr[(vertices[from].cnt)++] = to;
}

void enqueue(Queue *queue, int v){
    Vert *tmp = (Vert*) malloc(sizeof(Vert));
    tmp->next = NULL;
    tmp->vert = v;
    if (queue->front == NULL){
        queue->front = tmp;
        queue->rear = tmp;
        return;
    }
    queue->rear->next = tmp;
    queue->rear = tmp;
}

int dequeue(Queue *queue){
    Vert *tmp = queue->front;
    int v = queue->front->vert;
    queue->front = queue->front->next;
    free(tmp);
    return v;
}

void bfs(int v){
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    int cur;

    enqueue(&queue, 0);
    while(queue.front != NULL){
        cur = dequeue(&queue);
        for (int i = 0; i < vertices[cur].cnt; i++){
            if (dist[vertices[cur].arr[i]] == -1){
                dist[vertices[cur].arr[i]] = dist[cur] + 1;
                enqueue(&queue, vertices[cur].arr[i]);
            }
        }
    }
}

int main(){
    int m, from, to;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        vertices[i].cnt = 0;
        vertices[i].cap = 1;
        vertices[i].arr = (int*) malloc(sizeof(int));
        dist[i] = -1;
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d", &from, &to);
        add(from - 1, to - 1);
    }

    dist[0] = 0;
    bfs(0);
    for (int i = 0; i < n; i++){
        printf("%d\n", dist[i]);
    }
    for (int i = 0; i < n; i++){
        free(vertices[i].arr);
    }
    return 0;
}
