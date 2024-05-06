#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int sum){ // total number of ways to make amount equal to sum
    int n=coins.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    for(int i=1; i<=sum; i++){
        dp[0][i]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j]=dp[i-1][j];
            if(j-coins[i-1]>=0){
                dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int minCoins(vector<int>& coins, int sum){ // minimum number of coins required to make amount equal to sum
    int n=coins.size();
    vector<int> dp(sum+1, INT_MAX);
    dp[0]=0;
    for(int i=1; i<=sum; i++){
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j]<0){
                break;
            }
            if(dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[sum]==INT_MAX){
        return -1;
    }
    return dp[sum];
}

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    int sum;
    cin>>sum;
    sort(coins.begin(), coins.end());
    int ans=coinChange(coins, sum);
    int mn=minCoins(coins, sum);
    cout<<ans<<endl;
    cout<<mn<<endl;
    return 0;
}