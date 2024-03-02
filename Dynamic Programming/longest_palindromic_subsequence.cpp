#include<bits/stdc++.h>
using namespace std;

int LPS(string s){
    int n=s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=n-1; i>=0; i--){
        dp[i][i]=1;
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1]+2; // add 2 if first and last character is same
            }
            else{
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s;
    cin>>s;
    int ans=LPS(s);
    cout<<ans<<endl;
    return 0;
}