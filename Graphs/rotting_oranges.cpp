#include<bits/stdc++.h>
using namespace std;

// 0 => empty cell, 1 => fresh orange, 2 => rotten orange
// in one second, all neighbouring fresh oranges of a rotten orange get rotten
// find minimum time for all oranges to get rotten, or -1 if not possible
int rottingOranges(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int fresh=0; // count of fresh oranges remaining
    queue<pair<int, int>> q; // add all rotten oranges to queue
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                fresh++;
            }
            else if(grid[i][j]==2){
                q.push({i, j});
            }
        }
    }
    if(fresh==0){
        return 0;
    }
    int time=0;
    vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()){
        int s=q.size();
        for(int i=0; i<s; i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            // for each rotten orange, convert its neighbouring fresh oranges to rotten and add to queue and repeat
            for(int j=0; j<4; j++){
                int newX=x+dir[j][0];
                int newY=y+dir[j][1];
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                    fresh--;
                    grid[newX][newY]=2;
                    q.push({newX, newY});
                }
            }
        }
        time++;
    }
    // end when no rotten oranges are left to be checked
    if(fresh>0){ // if any fresh oranges left
        return -1;
    }
    return time-1; // time-1 as we are checking for all the oranges which got rotten in the last second
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
    int ans=rottingOranges(grid);
    cout<<ans<<endl;
    return 0;
}