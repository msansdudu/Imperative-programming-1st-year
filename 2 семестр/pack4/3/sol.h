#ifndef EDGELISTS_SOL_579846984654
#define EDGELISTS_SOL_579846984654

typedef struct{
    int from, to;
    int weight;
} Edge;

int getVerticesCount();
int readEdge(Edge *oEdge);
void init();
void destroy();
int getEdgesCount(int iVertex);
Edge getIncidentEdge (int iVertex, int iIndex);
#endif