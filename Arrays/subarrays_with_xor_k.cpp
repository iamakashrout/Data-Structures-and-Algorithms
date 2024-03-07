#include<bits/stdc++.h>
using namespace std;

// number of subarrays with total xor k
int solve(vector<int>& a, int k){
    // using a^b=c, then a^c=b
    map<int, int> mp; // storing count of indices where xor of all is x
    mp[0]++;
    int Xor=0;
    int ans=0;
    for(int i=0; i<a.size(); i++){
        Xor^=a[i];
        ans+=mp[(Xor^k)]; // count all indices having xor Xor^k
        mp[Xor]++;
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