#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int s,d;
};

class Graph{
    public:
        vector<vector<int>> adjList;
        Graph(vector<Edge> edges, int n){
            adjList.resize(n);

            for (auto edge : edges){
                adjList[edge.s].push_back(edge.d);
                adjList[edge.d].push_back(edge.s);
            }
        }
};

void R_DFS(Graph g, int i, vector<bool> &visit){
    
    cout << "Visit => " << i << endl;
    visit[i] = true;
    
    for (auto u : g.adjList[i]){
        if (!visit[u]){
            R_DFS(g,u,visit);
        }
    }
}

void R_BFS(Graph g, queue<int> q, vector<bool> &visit){

    if (q.empty()) return;

    int v = q.front();
    q.pop();
    cout << "Visit => " << v << "\n";

    for (int u : g.adjList[v]){
        if (!visit[u]){
            visit[u] = true;
            q.push(u);
        }
    }
    R_BFS(g, q, visit);
}

int main(){
    cout<<"\nEnter number of vertices : ";
    int n;
    cin>>n;

    cout<<"\nEnter number of edges : ";
    int e;
    cin>>e;

    vector<Edge> edges;
    int v1,v2;
    Edge E;
    for (int i = 0; i < e; i++){
        cout<<"\nEnter source vertex of edge "<<i+1<<" : ";
        cin>>v1;
        cout<<"\nEnter destination vertex of edge "<<i+1<<" : ";
        cin >> v2;
        E.s = v1;
        E.d = v2;
        edges.push_back(E);
    }

    Graph g(edges, n);

    int ch = 0;
    while (ch != 3){
        cout << "\n---------------: Main Menu :---------------\n 1] DFS Traversal. \n 2] BFS Traversal. \n 3] To Exit. \n ------------------------------------------- \n\t Enter Choice : ";
        cin >> ch;
        switch (ch){
            case 1:{
                vector<bool> visit(n, false);
                cout << "\nEnter vertex to initialize DFS : ";
                int p;
                cin >> p;
                R_DFS(g, p, visit);
                break;
            }
            case 2:{
                vector<bool> visit(n, false);
                queue<int> q;
                cout << "\nEnter vertex to initialize BFS : ";
                int p;
                cin >> p;
                q.push(p);
                visit[p] = true;
                R_BFS(g,q,visit);
                break;
            }
            case 3:{
                ch = 3;
                break;
            }
            default:{
                cout << "Enter a valid choice !!";
                break;
            }
        }
    }   
    return 0;
}