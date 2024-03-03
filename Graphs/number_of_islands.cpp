#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || visited[i][j]==1){
        return;
    }
    visited[i][j]=1;
    // solve for all neighbours
    solve(grid, i+1, j, visited, m, n);
    solve(grid, i-1, j, visited, m, n);
    solve(grid, i, j+1, visited, m, n);
    solve(grid, i, j-1, visited, m, n);
}

int numIslands(vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int ans=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                ans++; // increment ans for different components
                solve(grid, i, j, visited, m, n);
            }
        }
    }
    return ans;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int ans=numIslands(grid);
    cout<<ans<<endl;
    return 0;
}