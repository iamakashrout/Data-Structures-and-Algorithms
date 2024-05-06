#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    cin>>n>>r;
    r=min(r, n-r); // nCr=nC(n-r)
    vector<int> dp(r+1, 0);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=min(i, r); j>0; j--){
            dp[j]=dp[j-1]+dp[j]; // ncr=(n-1)Cr+(n-1)C(r-1)
        }
    }
    cout<<dp[r]<<endl;
    return 0;
}