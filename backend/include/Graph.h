#ifndef GRAPH_H
#define GRAPH_H

#include "Course.h"

struct Graph
{
    int n;
    int A[MAX_COURSE][MAX_COURSE];
};

void InitGraph(Graph &graph, int n);

void AddEdge(Graph &graph, int u, int v);

#endif
