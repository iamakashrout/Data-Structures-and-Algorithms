#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& stalls, int m, int x){
    // check if m cows can be placed with minimum distance x from each other
    int count=1;
    int prev=stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-prev>=x){
            count++;
            prev=stalls[i];
        }
        if(count==m){
            return true;
        }
    }
    return false;
}

int solve(vector<int>& stalls, int m){
    int n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int low=0, high=stalls[n-1];
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(stalls, m, mid)){ // check if mid cows can be placed, if yes then search for higher value
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> stalls(n);
    for(int i=0; i<n; i++){
        cin>>stalls[i];
    }
    int m;
    cin>>m;
    int ans=solve(stalls, m);
    cout<<ans;
    return 0;
}