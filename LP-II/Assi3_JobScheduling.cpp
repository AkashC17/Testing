#include <bits/stdc++.h>
using namespace std;

struct Job{
    char id;    
    int dead;   
    int profit; 
};

bool compare(Job a, Job b){
    return (a.profit > b.profit);
}

void JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);

    int result[n]; 
    bool slot[n];  

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++){
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--){
            if (slot[j] == false){
                result[j] = i;  
                slot[j] = true; 
                break;
            }
        }
    }

    cout<<"\n\nJob Sequence is : ";
    int maxProf=0;
    for (int i = 0; i < n; i++){
        if (slot[i]){
            cout << arr[result[i]].id << " ";
            maxProf+=arr[result[i]].profit;
        }
    }
    cout<<"\nMaximum profit is : "<<maxProf;  
}

int main()
{
    int n,prof,dead;
    char id;
    cout<<"Enter total number of jobs : ";
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter details of job "<<i+1<<" : ";
        cout<<"\n\tEnter ID of job : ";
        cin>>id;
        cout<<"\n\tEnter deadline of job : ";
        cin>>dead;
        cout<<"\n\tEnter profit of job : ";
        cin>>prof;
        arr[i].id = id;
        arr[i].dead = dead;
        arr[i].profit = prof;
    }

    cout<<"\n\tJob ID\t\tDeadline\tProfit";
    for(int i=0;i<n;i++){
        cout<<"\n\t"<<arr[i].id<<"\t\t"<<arr[i].dead<<"\t\t"<<arr[i].profit;
    }

    JobScheduling(arr, n);

    return 0;
}