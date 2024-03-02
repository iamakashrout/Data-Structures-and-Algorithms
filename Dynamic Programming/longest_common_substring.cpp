#include<bits/stdc++.h>
using namespace std;

int LCS(string s, string t){
    int m=s.size();
    int n=t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // dp[i][j] represents size of common substring ending at s[i] and t[j]
    int ans=0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1; // if char is same, add 1 to prev result
            }
            else{
                dp[i][j]=0; // if char is different then 0
            }
            ans=max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans=LCS(s, t);
    cout<<ans<<endl;
    return 0;
}