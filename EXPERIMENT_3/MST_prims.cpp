#include <bits/stdc++.h>
using namespace std;
#define V 5

int min_node(int nodes[], bool tree_set[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (tree_set[v] == false && nodes[v] < min)
            min = nodes[v], min_index = v;
    return min_index;
}

void _helper_print(int par[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << par[i] << " - " << i << " \t" << graph[i][par[i]] << " \n";
}

void primMST(int graph[V][V])
{
    int par[V];
    int nodes[V];
    bool tree_set[V];
    for (int i = 0; i < V; i++)
        nodes[i] = INT_MAX, tree_set[i] = false;
    nodes[0] = 0;
    par[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = min_node(nodes, tree_set);
        tree_set[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && tree_set[v] == false && graph[u][v] < nodes[v])
                par[v] = u, nodes[v] = graph[u][v];
    }
    _helper_print(par, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primMST(graph);
    return 0;
}
