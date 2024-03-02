#include<bits/stdc++.h>
using namespace std;

int LCS(string s, string t){
    int m=s.size();
    int n=t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1; // add 1 to the LCS obtained by removing last characters
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]); // take max of removing 1 character from string s and t
            }
        }
    }
    return dp[m][n];
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