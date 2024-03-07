#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    sort(v.begin(), v.end()); // sort according to start
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for(int i=1; i<n; i++){
        if(v[i][0]<=ans.back()[1]){ // if next interval starts before current ends, merge them and update end time
            ans.back()[1]=max(ans.back()[1], v[i][1]);
        }
        else{
            ans.push_back(v[i]); // else put in separate interval
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}