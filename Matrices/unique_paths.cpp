#include<bits/stdc++.h>
using namespace std;

// total ways to reach cell (m-1, n-1) from (0, 0)
int main(){
    int m, n;
    cin>>m>>n;
    vector<int> paths(n, 1); // paths[i] number of paths to reach column i
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            // total ways=no. of ways from left dp[j-1] + no. of ways from top dp[j]
            // repeat for rows 1 to m-1
            paths[j]=paths[j]+paths[j-1];
        }
    }
    cout<<paths[n-1]<<endl;
    return 0;
}