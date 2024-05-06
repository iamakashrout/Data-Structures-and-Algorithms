#include<bits/stdc++.h>
using namespace std;

// finding starting point if possible to complete cycle

int main(){
    int n;
    cin>>n;
    vector<int> gas(n);
    for(int i=0; i<n; i++){
        cin>>gas[i];
    }
    vector<int> cost(n);
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }
    int totalGas=0;
    int gasLeft=0;
    int start=0;
    for(int i=0; i<n; i++){
        totalGas+=(gas[i]-cost[i]);
        gasLeft+=(gas[i]-cost[i]);
        if(gasLeft<0){ // start from next stations where gas left became negative
            gasLeft=0;
            start=i+1;
        }
    }
    if(totalGas>=0){ // total gas should be greater than or equal to total cost
        cout<<start<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}