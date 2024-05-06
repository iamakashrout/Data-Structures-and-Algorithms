#include<bits/stdc++.h>
using namespace std;

vector<int> mergeK(vector<vector<int>>& v){
    int m=v.size();
    int n=v[0].size();
    // store value and index in pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans;
    vector<int> index(m, 0);
    for(int i=0; i<m; i++){
        pq.push({v[i][0], i}); // smallest elements of all arrays
    }
    while(!pq.empty()){
        int val=pq.top().first;
        int i=pq.top().second;
        ans.push_back(val);
        pq.pop();
        if(index[i]!=n-1){
            index[i]++; // add next element of array from which smallest number was removed
            pq.push({v[i][index[i]], i});
        }
    }
    return ans;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> v(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    vector<int> ans=mergeK(v);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}