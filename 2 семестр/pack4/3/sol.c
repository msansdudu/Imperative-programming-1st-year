//#include "sol.h"
#include <stdlib.h>
#include <stdio.h>
#include "sol.h"

//typedef struct{
//    int from, to;
//    int weight;
//} Edge;

typedef struct{
    int cnt, cap;
    Edge *arr;
} vertex;

vertex *vertices = NULL;

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