#include <iostream>
using namespace std;

class Graph
{
private:
    int tot_ver, tot_edge;
    int **adj_Mat;

public:
    Graph()
    {
        tot_ver = 1;
        tot_edge = 0;
        adj_Mat = new int *[tot_ver];
        for (int i = 0; i < tot_ver; i++)
        {
            adj_Mat[i] = new int[tot_ver];
        }
        for (int i = 0; i < tot_ver; i++)
        {
            for (int j = 0; j < tot_ver; j++)
            {
                adj_Mat[i][j] = 0;
            }
        }
    }

    Graph(int v, int e)
    {
        tot_ver = v;
        tot_edge = e;
        adj_Mat = new int *[tot_ver];
        for (int i = 0; i < tot_ver; i++)
        {
            adj_Mat[i] = new int[tot_ver];
        }
        for (int i = 0; i < tot_ver; i++)
        {
            for (int j = 0; j < tot_ver; j++)
            {
                adj_Mat[i][j] = 0;
            }
        }
    }

    void create_Graph();
    void display(int **);
    void kruskal();

    ~Graph() {}
};

void Graph ::create_Graph()
{
    for (int i = 0; i < tot_edge; i++)
    {
        int ver1, ver2, weight;
        cout << "\n\t Enter edge No " << i + 1 << " : " << endl;
        cout << "\n\t Enter vertex1 : ";
        cin >> ver1;
        cout << "\n\t Enter vertex2 : ";
        cin >> ver2;
        cout << "\n\t Enter weight of edge : ";
        cin >> weight;
        cout << "\n\t -----------------------------";

        adj_Mat[ver1][ver2] = weight;
        adj_Mat[ver2][ver1] = weight;
    }
    cout << "\n\t Adjacency Matrix : " << endl;
    display(adj_Mat);
}

void Graph ::display(int **arr)
{
    cout << "\n";
    for (int i = 0; i < tot_ver; i++)
    {
        cout << "\t\t\t ";
        for (int j = 0; j < tot_ver; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}

void Graph ::kruskal()
{
    int adj_Mat2[tot_ver][tot_ver];
    for (int i = 0; i < tot_ver; i++)
    {
        for (int j = 0; j < i; j++)
        {
            adj_Mat2[i][j] = adj_Mat[i][j];
            adj_Mat2[j][i] = adj_Mat[j][i];
        }
    }
    int count = 0, min, wt = 0, t1, t2;
    int father[tot_ver];
    for (int i = 0; i < tot_ver; i++)
    {
        father[i] = -1;
    }
    int **res = new int *[tot_ver];
    for (int i = 0; i < tot_ver; i++)
    {
        res[i] = new int[tot_ver];
    }
    for (int i = 0; i < tot_ver; i++)
    {
        for (int j = 0; j < tot_ver; j++)
        {
            res[i][j] = 0;
        }
    }
    while (count < tot_ver - 1)
    {
        min = 999999;
        for (int v1 = 0; v1 < tot_ver; v1++)
        {
            for (int v2 = 0; v2 < tot_ver; v2++)
            {
                if (adj_Mat2[v1][v2] != 0 && adj_Mat2[v1][v2] < min)
                {
                    min = adj_Mat2[v1][v2];
                    t1 = v1;
                    t2 = v2;
                }
            }
        }
        int temp1 = t1, root_temp1;
        int temp2 = t2, root_temp2;
        adj_Mat2[temp1][temp2] = adj_Mat2[temp2][temp1] = 0;
        while (t1 >= 0)
        {
            root_temp1 = t1;
            t1 = father[t1];
        }
        while (t2 >= 0)
        {
            root_temp2 = t2;
            t2 = father[t2];
        }
        if (root_temp1 != root_temp2)
        {
            res[temp1][temp2] = res[temp2][temp1] = min;
            wt += res[temp1][temp2];
            father[root_temp2] = root_temp1;
            count++;
        }
    }
    cout << "\n\t Minimum cost required : " << wt << endl;
    cout << "\n\t Minimum Spanning Tree : " << endl;
    display(res);
}

int main()
{
    int vertex, edges, choice, start;
    cout << "\n\t Enter number of vertices: ";
    cin >> vertex;
    cout << "\n\t Enter number of edges: ";
    cin >> edges;
    Graph g1(vertex, edges);
    g1.create_Graph();
    g1.kruskal();

    return 0;
}