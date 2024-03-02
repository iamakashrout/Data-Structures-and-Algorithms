#include<bits/stdc++.h>
using namespace std;

int editDistance(string s, string t){
    int m=s.size();
    int n=t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=0; i<=m; i++){
        dp[i][0]=i; // if t is empty, remove all characters from s
    }
    for(int i=1; i<=n; i++){
        dp[0][i]=i; // if s is empty, add all characters of t to s
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]; // if char is same, no new operation required
            }
            else{
                dp[i][j]=1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                // dp[i-1][j-1] means replaced current character with required character with rest of string being same
                // dp[i-1][j] means removed current character from s
                // dp[i][j-1] means added new character to s
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
    int ans=editDistance(s, t);
    cout<<ans<<endl;
    return 0;
}