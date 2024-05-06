#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& grid, int val, int row, int col){
    for(int i=0; i<9; i++){
        if(grid[row][i]==val || grid[i][col]==val){ // check for same row and column
            return false;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[row-row%3+i][col-col%3+j]==val){ // check for 3x3 box
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& grid){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(grid[i][j]==0){ // if cell empty
                for(int k=1; k<=9; k++){
                    if(isValid(grid, k, i, j)){ // check if value is safe
                        grid[i][j]=k;
                        if(solve(grid)){ // solve for rest of grid
                            return true;
                        }
                        grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> grid(9, vector<int>(9));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>grid[i][j];
        }
    }
    if(solve(grid)==true){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}