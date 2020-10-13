#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 9;

    int graph[9][9] = {
        {100, 4, 100, 100, 100, 100, 100, 8, 100},
        {4, 100, 8, 100, 100, 100, 100, 100, 100},
        {100, 8, 100, 7, 100, 4, 100, 100, 2},
        {100, 100, 7, 100, 9, 14, 100, 100, 100},
        {100, 100, 100, 9, 100, 10, 100, 100, 100},
        {100, 100, 4, 14, 10, 100, 2, 100, 100},
        {100, 100, 100, 100, 100, 2, 100, 1, 6},
        {8, 100, 100, 100, 100, 100, 1, 100, 7},
        {100, 100, 2, 100, 100, 100, 6, 7, 100}};

    int parent[n];

    int edges[100][3];
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (graph[i][j] != 100)
            {
                edges[count][0] = i;
                edges[count][1] = j;
                edges[count++][2] = graph[i][j];
            }
        }

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (edges[j][2] > edges[j + 1][2])
            {
                int t1 = edges[j][0], t2 = edges[j][1], t3 = edges[j][2];

                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];

                edges[j + 1][0] = t1;
                edges[j + 1][1] = t2;
                edges[j + 1][2] = t3;
            }

    int mst[n - 1][2];
    int mstVal = 0;
    int l = 0;

    cout << endl;

    for (int i = 0; i < n; i++)
        parent[i] = -1;
    cout << endl;

    for (int i = 0; i < count; i++)
    {
        if ((parent[edges[i][0]] == -1 && parent[edges[i][1]] == -1))
        {
            parent[edges[i][0]] = edges[i][0];
            parent[edges[i][1]] = edges[i][0];

            mst[l][0] = edges[i][0];
            mst[l++][1] = edges[i][1];

            mstVal += edges[i][2];
        }

        else if ((parent[edges[i][0]] == -1 && parent[edges[i][1]] != -1))
        {
            parent[edges[i][0]] = parent[edges[i][1]];

            mst[l][0] = edges[i][1];
            mst[l++][1] = edges[i][0];

            mstVal += edges[i][2];
        }

        else if ((parent[edges[i][0]] != -1 && parent[edges[i][1]] == -1))
        {
            parent[edges[i][1]] = parent[edges[i][0]];

            mst[l][0] = edges[i][0];
            mst[l++][1] = edges[i][1];

            mstVal += edges[i][2];
        }

        else if (parent[edges[i][0]] != -1 && parent[edges[i][1]] != -1 && parent[edges[i][0]] != parent[edges[i][1]])
        {
            int p = parent[edges[i][1]];
            for (int j = 0; j < n; j++)
                if (parent[j] == p)
                    parent[j] = parent[edges[i][0]];

            mst[l][0] = edges[i][0];
            mst[l++][1] = edges[i][1];

            mstVal += edges[i][2];
        }
    }

    for (int i = 0; i < l; i++)
        cout << mst[i][0] << " -> " << mst[i][1] << endl;

    cout << endl;
    cout << mstVal << endl;

    return (0);
}