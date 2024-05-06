#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board, int n, vector<vector<int>>& ans){
    vector<int> temp; // current ans
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==1){
                temp.push_back(j+1);
                break;
            }
        }
    }
    ans.push_back(temp);
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n){
    for(int i=0; i<row; i++){ // check for same column
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){ // check for left diagonal
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){ // check for right diagonal
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void solve(vector<vector<int>>& board, int row, int n, vector<vector<int>>& ans){
    if(row==n){ // all rows covered
        addSolution(board, n, ans);
        return;
    }
    for(int i=0; i<n; i++){
        if(isSafe(board, row, i, n)){ // check if safe to place queen
            board[row][i]=1;
            solve(board, row+1, n, ans); // check for next row
            board[row][i]=0; // backtrack
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0)); // represents the state of board where 1 means queen is placed
    vector<vector<int>> ans; // solutions where values represent column number of queen in each row
    solve(board, 0, n, ans);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}