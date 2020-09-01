#include <iostream>
using namespace std;

int intersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            cout << arr2[j++];
            i++;
        }
    }
}

int main()
{
    int V1[] = {0, 1};
    int V2[] = {0, 1, 2};
    int m = sizeof(V1) / sizeof(V1[0]);
    int n = sizeof(V2) / sizeof(V2[0]);
    int E1[m][m], E2[n][n], E3[m + n][m + n];
    int i, j, k;
    cout << "Enter the adjacency matrix(symmetric) for graph G1:\n";
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            cout << "E1[" << i << "][" << j << "]=";
            cin >> E1[i][j];
        }
    printf("Enter the adjacency matrix(symmetric) for graph G2:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("E2[%d][%d]=", i, j);
            scanf("%d", &E2[i][j]);
        }

    cout << "\nSet of vertices in intersection of the graphs G1 and G2 is:\n";
    intersection(V1, V2, m, n);
    cout << "\n";
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            if (E1[i][j] > E2[i][j])
                E3[i][j] = E1[i][j];
            else
                E3[i][j] = E2[i][j];
        }

    cout << "Adjacency matrix of intersection of graphs G1 and G2 is:\n\t";

    for (i = 0; i < m; i++)
        cout << i << "\t";
    cout << "\n\t";
    for (i = 0; i < m; i++)
        cout << " ";
    for (i = 0; i < m; i++)
    {
        cout << "\n"
             << i << "|\t";
        for (j = 0; j < m; j++)
        {
            cout << E3[i][j] << "\t";
        }
    }
    cout << endl;
    return 0;
}