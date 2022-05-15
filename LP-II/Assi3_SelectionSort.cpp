#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int tmp = a[i];
                a[i] =a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"\n Enter size of array : ";
    cin>>n;

    int a[n];
    cout<<"\n Enter elements : \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"\nArray before sorting : \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    selection_sort(a,n);

    cout<<"\nArray after sorting : \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}