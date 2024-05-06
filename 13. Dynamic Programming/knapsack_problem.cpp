#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<int>& values, vector<int>& weights, int w){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            dp[i][j]=dp[i-1][j];
            if(j-weights[i-1]>=0){ // check if item can be taken
                dp[i][j]=max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]); // take max of take and not take cases
            }
        }
    }
    return dp[n][w];
}

int main(){
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0; i<n; i++){
        cin>>values[i];
    }
    vector<int> weights(n);
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    int w;
    cin>>w;
    int ans=knapsack(n, values, weights, w);
    cout<<ans<<endl;
    return 0;
}