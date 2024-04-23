#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a){
    int curr=0; // max value robbed after current index
    int prev1=0; // max value robbed after previous index
    int prev2=0; // max value robbed after second previous index
    for(int i=0; i<a.size(); i++){
        curr=max(prev1, prev2+a[i]); // max of take and not take values
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}