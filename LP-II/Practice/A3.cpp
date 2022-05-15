#include <bits/stdc++.h>
using namespace std;

class graph{
    private:
        int **adjMat;
        int tv,te;
    
    public:
        graph(){
            tv=1;
            te=0;
            adjMat = new int *[tv];
            for(int i=0;i<tv;i++){
                adjMat[i] = new int[tv];
                for(int j=0;j<tv;j++){
                    adjMat[i][j]=0;
                }
            }
        }

        graph(int v,int e){
            tv=v;
            te=e;
            adjMat = new int *[tv];
            for(int i=0;i<tv;i++){
                adjMat[i] = new int[tv];
                for(int j=0;j<tv;j++){
                    adjMat[i][j]=0;
                }
            }
        }

        void create();
        void show(int **);
        void kruskal();

        ~graph(){}
};

void graph::create(){
    int v1,v2,w;
    for(int i=0;i<te;i++){
        cout<<"Enter details for edge "<<i+1<<endl;
        cout<<"Enter v1 ";
        cin>>v1;
        cout<<"Enter v2 ";
        cin>>v2;
        cout<<"Enter weight ";
        cin>>w;
        adjMat[v1][v2]=w;
        adjMat[v2][v1]=w;
    }
    show(adjMat);
}

void graph::show(int **adj){
    cout<<endl;
    for(int i=0;i<tv;i++){
        for(int j=0;j<tv;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void graph::kruskal(){
    int adj2[tv][tv];
    for(int i=0;i<tv;i++){
        for(int j=0;j<i;j++){
            adj2[i][j] = adjMat[i][j];
            adj2[j][i] = adjMat[j][i];
        }
    }
    int **res = new int *[tv];
    for(int i=0;i<tv;i++){
        res[i]=new int[tv];
        for(int j=0;j<tv;j++){
            res[i][j]=0;
        }
    }

    int cnt=0,wt=0,min,t1,t2;
    int father[tv];
    for(int i=0;i<tv;i++){
        father[i]=-1;
    }
    while(cnt<(tv-1)){
        min=999999;
        for(int i=0;i<tv;i++){
            for(int j=0;j<tv;j++){
                if(adj2[i][j]!=0 && adj2[i][j]<min){
                    min=adj2[i][j];
                    t1 = i;
                    t2 = j;
                }
            }
        }
        int tmp1 = t1,rt1;
        int tmp2 = t2,rt2;
        adj2[tmp1][tmp2]=0;
        adj2[tmp2][tmp1]=0;
        while(t1>=0){
            rt1 = t1;
            t1=father[t1];
        }
        while(t2>=0){
            rt2 = t2;
            t2=father[t2];
        }
        if(rt1!=rt2){
            res[tmp1][tmp2]=min;
            res[tmp2][tmp1]=min;
            wt+=min;
            father[rt2] = rt1;
            cnt++;
        }
    }
    cout<<"Minimum wt "<<wt<<endl;
    show(res);
}

int main(){

    int v,e;
    cout<<"Vertices => ";
    cin>>v;
    cout<<"Edges => ";
    cin>>e;

    graph g(v,e);
    g.create();
    g.kruskal();

    return 0;
}