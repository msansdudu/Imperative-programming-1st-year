#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int from, to;
    int weight;
} Edge;

typedef struct{
    int cnt, cap;
    Edge *arr;
} vertex;

vertex *vertices = NULL;
int flag = 1, id = 0, count = 0, help = 0;
Edge *arr = NULL;

int getVerticesCount();
int readEdge(Edge *oEdge);

int getVerticesCount(){
    if (flag){
        scanf("%d", &count);
        scanf("%d", &help);
        flag = 0;
        arr = malloc(sizeof(Edge)*help);
        for (int i = 0; i<help; i++){
            scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].weight);
        }
    }
    return count;
}

int readEdge(Edge *oEdge){
    if (id < help){
        oEdge->from = arr[id].from;
        oEdge->to = arr[id].to;
        oEdge->weight = arr[id].weight;
        id++;
        return 1;
    }
    return 0;
}

void init(){
    int n = getVerticesCount();
    vertices = (vertex*) malloc(n * sizeof(vertex));
    for (int i = 0; i < n; i++){
        vertices[i].cnt = 0;
        vertices[i].cap = 1;
        vertices[i].arr = (Edge*) malloc(sizeof(Edge));
    }

    Edge oEdge;
    while(readEdge(&oEdge)){
        if (vertices[oEdge.from].cap <= vertices[oEdge.from].cnt){
            vertices[oEdge.from].cap *= 2;
            vertices[oEdge.from].arr = realloc(vertices[oEdge.from].arr, vertices[oEdge.from].cap * sizeof(Edge));
	    }
	    vertices[oEdge.from].arr[(vertices[oEdge.from].cnt)++] = oEdge;

        if (vertices[oEdge.to].cap <= vertices[oEdge.to].cnt){
            vertices[oEdge.to].cap *= 2;
            vertices[oEdge.to].arr = realloc(vertices[oEdge.to].arr, vertices[oEdge.to].cap * sizeof(Edge));
	    }
	    vertices[oEdge.to].arr[vertices[oEdge.to].cnt].weight = oEdge.weight;
        vertices[oEdge.to].arr[vertices[oEdge.to].cnt].to = oEdge.from;
        vertices[oEdge.to].arr[(vertices[oEdge.to].cnt)++].from = oEdge.to;
    }
}

void destroy(){
    int n = getVerticesCount();
    for (int i = 0; i < n; i++){
        free(vertices[i].arr);
    }
    free(vertices);
}

int getEdgesCount(int iVertex){
    return vertices[iVertex].cnt;
}

Edge getIncidentEdge (int iVertex, int iIndex){
    return vertices[iVertex].arr[iIndex];
}

int main(){
    Edge oEdge;
    init();
    
    printf("%d\n", getEdgesCount(0));
    oEdge = getIncidentEdge(0, 0);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(0, 1);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);


    printf("%d\n", getEdgesCount(1));
    oEdge = getIncidentEdge(1, 0);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(1, 3);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(1, 2);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(1, 1);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);


    printf("%d\n", getEdgesCount(2));
    oEdge = getIncidentEdge(2, 0);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(2, 1);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);


    printf("%d\n", getEdgesCount(3));
    oEdge = getIncidentEdge(3, 0);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);


    printf("%d\n", getEdgesCount(4));
    oEdge = getIncidentEdge(4, 2);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(4, 0);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    oEdge = getIncidentEdge(4, 1);
    printf("%d %d %d\n", oEdge.from, oEdge.to, oEdge.weight);
    destroy();
    return 0;
}