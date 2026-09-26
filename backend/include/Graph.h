#ifndef GRAPH_H
#define GRAPH_H

#define MAX_COURSE 100

struct Graph
{
    int n;
    int A[MAX_COURSE][MAX_COURSE];
};

void InitGraph(Graph &graph, int n);

void AddEdge(Graph &graph, int u, int v);

void OutputGraph(Graph graph);

#endif