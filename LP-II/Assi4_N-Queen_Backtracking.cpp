#include <bits/stdc++.h>
using namespace std;

bool is_safe(int **arr,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1) return false;
    }
    int row = x,col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1) return false;
        row--;
        col--;
    }
    row=x,col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1) return false;
        row--;
        col++;
    }
    return true;
}

bool N_Queen(int **arr,int x,int n){
    if(x==n) return true;
    for(int col=0;col<n;col++){
        if(is_safe(arr,x,col,n)){
            arr[x][col]=1;
            if(N_Queen(arr,x+1,n)) return true;
            arr[x][col]=0; // Backtracking..............
        }
    }
    return false;
}


int main(){
    int n;
    cout<<"Enter size of chess board : ";
    cin>>n;
    int **a = new int *[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    if(N_Queen(a,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl; 
        }
    }else cout<<"Non Solvable";
    return 0;
}