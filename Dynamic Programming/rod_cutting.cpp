#include<bits/stdc++.h>
using namespace std;

int rodCutting(int n, vector<int>& cuts){
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m=cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for(int left=m-1; left>=0; left--){
        for(int right=left+1; right<m; right++){
            for(int i=left+1; i<right; i++){
                int curr=cuts[right]-cuts[left]+dp[left][i]+dp[i][right];
                // cuts[right]-cuts[left] is the length of rod being cut at position i
                // dp[left][i] and dp[i][right] are the answers for the two cut portions
                if(dp[left][right]==0){
                    dp[left][right]=INT_MAX;
                }
                dp[left][right]=min(dp[left][right], curr);
            }
        }
    }
    return dp[0][m-1];
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> cuts(m);
    for(int i=0; i<m; i++){
        cin>>cuts[i];
    }
    int ans=rodCutting(n, cuts);
    cout<<ans<<endl;
    return 0;
}