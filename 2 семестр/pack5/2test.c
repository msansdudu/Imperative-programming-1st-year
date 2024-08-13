#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node{ 
    int vertex; 
    struct Node* next; 
} Node; 
 
typedef struct Queue{ 
    Node* front; 
    Node* rear; 
}Queue; 
 
void enqueue(Queue* q, int vertex){ 
    Node* new_node = (Node*)malloc(sizeof(Node)); 
    new_node->vertex = vertex; 
    new_node->next = NULL; 
    if (q->rear == NULL){ 
        q->front = new_node; 
        q->rear = new_node; 
    } 
    else{ 
        q->rear->next = new_node; 
        q->rear = new_node; 
    } 
} 
 
int dequeue(Queue* q){ 
    if (q->front == NULL){ 
        return -1; 
    } 
    else{ 
        int vertex = q->front->vertex; 
        Node* temp = q->front; 
        q->front = q->front->next; 
        if(q->front == NULL){ 
            q->rear = NULL; 
        } 
        free(temp); 
        return vertex; 
    } 
} 
 
void shortest_paths(int N, int M, Node** graph){ 
    Queue q; 
    q.front = q.rear = NULL; 
 
    int* distances = (int*)malloc(N * sizeof(int)); 
    for (int i = 0; i < N; i++){ 
        distances[i] = -1; 
    } 
 
    distances[0] = 0; 
    enqueue(&q, 0); 
 
    while(q.front != NULL){ 
        int current = dequeue(&q); 
 
        Node* temp = graph[current]; 
        while(temp != NULL){ 
            if (distances[temp->vertex] == -1){ 
                distances[temp->vertex] = distances[current] + 1; 
                enqueue(&q, temp->vertex); 
            } 
            temp = temp->next; 
        } 
    } 
 
    for (int i = 0; i < N; i++){ 
        printf("%d\n", distances[i]); 
    } 
 
    free(distances); 
} 
 
int main(){ 
    int M, N; 
    if (scanf("%d %d", &N, &M) != 2){ 
        printf("error"); 
    } 
    else{ 
        Node** graph = (Node**)malloc(N * sizeof(Node*)); 
        for (int i = 0; i < N; i++){ 
            graph[i] = NULL; 
        } 
        for (int i = 0; i < M; i++){ 
            int u, v; 
            if (scanf("%d %d", &u, &v) != 2){ 
                printf("ërror"); 
            } 
            else{ 
                    Node* new_node = (Node*)malloc(sizeof(Node)); 
                    new_node->vertex = v - 1; 
                    new_node->next = graph[u - 1]; 
                        graph[u - 1] = new_node; 
            } 
        } 
        shortest_paths(N, M, graph); 
        for (int i = 0; i < N; i++){ 
            Node* temp = graph[i]; 
            while(temp != NULL){ 
                Node* del = temp; 
                temp = temp->next; 
                free(del); 
            } 
        } 
        free(graph); 
    } 
 
    return 0; 
}
