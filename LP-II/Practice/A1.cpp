#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int s,d;
};

class Graph{
    public:
        vector<vector<int>> adjList;
        Graph(vector<Edge> v,int n){
            adjList.resize(n);
            for(auto edge : v){
                adjList[edge.d].push_back(edge.s);
                adjList[edge.s].push_back(edge.d);
            }
        }
};

void R_DFS(Graph g,int i,vector<bool> &visit){
    cout<<"Visit => "<<i<<endl;
    visit[i] = true;
    for(auto u:g.adjList[i]){
        if(!visit[u]){
            R_DFS(g,u,visit);
        }
    }
}

void R_BFS(Graph g,queue<int> q,vector<bool> &visit){
    if(q.empty()) return;
    int p = q.front();
    q.pop();
    cout<<"Visit => "<<p<<endl;
    for(int u:g.adjList[p]){
        if(!visit[u]){
            visit[u] = true;
            q.push(u);
        }
    }
    R_BFS(g,q,visit);
}

int main(){
    int v,e;
    cout<<"Enter vertices : ";
    cin>>v;
    cout<<"Enter edges :";
    cin>>e;
    vector<Edge> ve;
    
    Edge ed;
    int v1,v2;
    for(int i=0;i<e;i++){
        cout<<"Enter details for edge "<<i+1<<" : ";
        cout<<"Enter sorce vertex : ";
        cin>>v1;
        cout<<"Enter destination vertex : ";
        cin>>v2;
        ed.d=v2;
        ed.s=v1;
        ve.push_back(ed);
    }

    Graph g(ve,v);

    int ch=0;
    while(ch!=3){
        cout<<"\n 1] DFS \n 2] BFS \n 3] Exit \n Ente choice : ";
        cin>>ch;
        switch(ch){
            case 1:{
                vector<bool> visit(v,false);
                int k;
                cout<<"Enter initial vertex : ";
                cin>>k;
                R_DFS(g,k,visit);
                break;
            }
            case 2:{
                vector<bool> visit(v,false);
                int k;
                queue<int> q;
                cout<<"Enter initial vertex : ";
                cin>>k;
                visit[k]=true;
                q.push(k);
                R_BFS(g,q,visit);
                break;
            }
            case 3:{
                ch=3;
                break;
            }
            default:{
                cout<<"Enter Valid choice.";
            }
        }
    }
    return 0;
}