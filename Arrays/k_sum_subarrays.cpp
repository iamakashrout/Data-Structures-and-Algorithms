#include<bits/stdc++.h>
using namespace std;

// number of subarrays with sum k
int solve(vector<int>& a, int k){
    map<int, int> mp;
    mp[0]=1; // mp[x] gives count of indexes till which total sum is x
    int sum=0; // sum of all elements till now
    int ans=0;
    for(int i=0; i<a.size(); i++){
        sum+=a[i];
        ans+=mp[sum-k];
        mp[sum]++;
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
    int ans=solve(a, k);
    cout<<ans<<endl;
    return 0;
}