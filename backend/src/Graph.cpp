#include "Graph.h"

void InitGraph(Graph &graph, int n)
{
    graph.n = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph.A[i][j] = 0;
        }
    }
}

void AddEdge(Graph &graph, int u, int v)
{
    if (u < 0 || u >= graph.n ||
        v < 0 || v >= graph.n)
    {
        return;
    }

    graph.A[u][v] = 1;
    graph.A[v][u] = 1;
}
