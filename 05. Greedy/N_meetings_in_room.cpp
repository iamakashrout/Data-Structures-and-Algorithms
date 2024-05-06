#include<bits/stdc++.h>
using namespace std;

// ACTITIVITY SELECTION PROBLEM

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> meetings(n);
    for(int i=0; i<n; i++){
        cin>>meetings[i].first>>meetings[i].second;
    }
    // sort according to end time
    sort(meetings.begin(), meetings.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second<b.second;
    });
    int ans=1;
    int prev=meetings[0].second;
    for(int i=1; i<n; i++){
        if(meetings[i].first>prev){
            ans++;
            prev=meetings[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}