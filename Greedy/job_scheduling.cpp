#include<bits/stdc++.h>
using namespace std;

// maximizing profits by taking jobs within deadlines

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> jobs(n);
    for(int i=0; i<n; i++){
        cin>>jobs[i].first>>jobs[i].second;
    }
    // sort according to profits
    sort(jobs.begin(), jobs.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second>b.second;
    });
    int lastDeadline=jobs[0].first;
    for(int i=1; i<n; i++){
        lastDeadline=max(lastDeadline, jobs[i].first);
    }
    vector<int> slots(lastDeadline+1, -1);
    int job=0;
    int profit=0;
    // fill jobs at the last possible slots
    for(int i=0; i<n; i++){
        for(int j=jobs[i].first; j>0; j--){
            if(slots[j]==-1){
                slots[j]=i;
                job++;
                profit+=jobs[i].second;
                break;
            }
        }
    }
    cout<<job<<endl;
    cout<<profit<<endl;
    return 0;
}