#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& a, int k){
    vector<int> ans;
    deque<int> dq; // stores possible values in current window
    for(int i=0; i<a.size(); i++){
        while(!dq.empty() && a[dq.back()]<=a[i]){ // remove all smaller values than last element of window
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(a[dq.front()]); // smallest value of window
        }
        if(dq.front()<=i-k+1){ // if earliest value would be removed from next window
            dq.pop_front();
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    vector<int> ans=solve(a, k);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}