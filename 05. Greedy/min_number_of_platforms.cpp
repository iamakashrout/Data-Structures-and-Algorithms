#include<bits/stdc++.h>
using namespace std;

// MINIMUM RESOURCES PROBLEM

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> trains(n);
    for(int i=0; i<n; i++){
        cin>>trains[i].first>>trains[i].second;
    }
    // sort both starting and ending times
    vector<int> start;
    for(int i=0; i<n; i++){
        start.push_back(trains[i].first);
    }
    sort(start.begin(), start.end());
    vector<int> finish;
    for(int i=0; i<n; i++){
        finish.push_back(trains[i].second);
    }
    sort(finish.begin(), finish.end());
    int ans=1;
    int j=0;
    for(int i=1; i<n; i++){
        if(start[i]>finish[j]){
            j++;
        }
        else{
            ans++; // if new task starts before previous ends, then new resource required
        }
    }
    cout<<ans<<endl;
    return 0;
}