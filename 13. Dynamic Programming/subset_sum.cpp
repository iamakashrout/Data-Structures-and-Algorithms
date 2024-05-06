#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a, int sum){
    int n=a.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    for(int i=1; i<=sum; i++){
        dp[0][i]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j<a[i-1]){
                dp[i][j]=dp[i-1][j]; // if element greater than remaining sum, cant take it
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]]; // check both take and not take cases
            }
        }
    }
    if(dp[n][sum]==1){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int sum=0;
    cin>>sum;
    sort(a.begin(), a.end());
    if(solve(a, sum)==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}