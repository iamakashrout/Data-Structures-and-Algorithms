#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m-1][n-1]=matrix[m-1][n-1];
    for(int i=m-2; i>=0; i--){
        dp[i][n-1]=dp[i+1][n-1]+matrix[i][n-1]; // last column
    }
    for(int i=n-2; i>=0; i--){
        dp[m-1][i]=dp[m-1][i+1]+matrix[m-1][i]; // last row
    }
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            dp[i][j]=min(dp[i+1][j], dp[i][j+1])+matrix[i][j]; // take min value path from right or down paths
        }
    }
    return dp[0][0];
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    int ans=solve(matrix);
    cout<<ans<<endl;
    return 0;
}