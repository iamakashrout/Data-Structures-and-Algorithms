#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1 || n==2){
        cout<<1<<endl;
    }
    else{
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[2]=1;
        for(int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}