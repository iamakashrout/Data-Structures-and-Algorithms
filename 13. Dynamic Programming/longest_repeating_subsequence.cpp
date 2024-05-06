#include<bits/stdc++.h>
using namespace std;

int LRS(string s){
    int n=s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    string a=s;
    string b=s;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1] && i!=j){
                dp[i][j]=dp[i-1][j-1]+1; // LCS in the same string
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string s;
    cin>>s;
    int ans=LRS(s);
    cout<<ans<<endl;
    return 0;
}