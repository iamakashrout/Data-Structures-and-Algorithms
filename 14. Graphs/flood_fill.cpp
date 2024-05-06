#include<bits/stdc++.h>
using namespace std;

// given a starting point (x, y) in grid, convert all it and all its neighbours with same value to a given value
void floodFill(vector<vector<int>>& grid, int m, int n, int val, int i, int j, int curr, vector<vector<int>>& visited){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=curr || visited[i][j]==1){
        // check range and if it has same value or has been already visited
        return;
    }
    visited[i][j]=1;
    grid[i][j]=val;
    // check for all neighbours
    floodFill(grid, m, n, val, i+1, j, curr, visited);
    floodFill(grid, m, n, val, i-1, j, curr, visited);
    floodFill(grid, m, n, val, i, j+1, curr, visited);
    floodFill(grid, m, n, val, i, j-1, curr, visited);
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int r, c;
    cin>>r>>c;
    int val;
    cin>>val;
    int curr=grid[r][c];
    vector<vector<int>> visited(m, vector<int>(n, 0));
    floodFill(grid, m, n, val, r, c, curr, visited);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}