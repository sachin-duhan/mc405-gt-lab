// Program to find the number of vertices, even vertices, odd vertices, and the number of edges in the graph.
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int countVertices() { return this->V; }

    int countEdges()
    {
        int sum = 0;
        for (int i = 0; i < V; i++)
            sum += adj[i].size();
        return sum / 2;
    }

    int countEvenVertices()
    {
        int count = 0;
        for (int i = 0; i < this->V; i++)
        {
            if (adj[i].size() % 2 == 0)
                count++;
        }
        return count;
    }

    int countOddVertices() { return this->V - countEvenVertices(); }
};

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);

    cout << "Number of edges are - " << g.countEdges() << endl;
    cout << "Number of Even edges are - " << g.countEvenVertices() << endl;
    cout << "Number of Odd edges are - " << g.countOddVertices() << endl;
    cout << "Number of vertices are - " << g.countVertices() << endl;

    return 0;
}