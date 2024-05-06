#include<bits/stdc++.h>
using namespace std;

// reach from cell (0, 0) to (n-1, n-1)
// cells with value 0 are blocked
// find all paths

void solve(vector<vector<int>>& maze, int n, int i, int j, string temp, vector<string>& ans){
    // temp represents the current path
    if(i==n-1 && j==n-1 && maze[i][j]==1){ // reached destination
        ans.push_back(temp);
        return;
    }
    if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0){
        return;
    }
    maze[i][j]=0;
    solve(maze, n, i+1, j, temp+"D", ans);
    solve(maze, n, i-1, j, temp+"U", ans);
    solve(maze, n, i, j+1, temp+"R", ans);
    solve(maze, n, i, j-1, temp+"L", ans);
    maze[i][j]=1; // backtrack
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>maze[i][j];
        }
    }
    vector<string> ans;
    solve(maze, n, 0, 0, "", ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}