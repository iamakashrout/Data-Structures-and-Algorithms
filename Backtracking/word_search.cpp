#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>>& board, string word, int i, int j, int index){
    if(index==word.size()){ // all indices found
        return true;
    }
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]){
        return false;
    }
    board[i][j]='*';
    bool a=solve(board, word, i+1, j, index+1);
    bool b=solve(board, word, i-1, j, index+1);
    bool c=solve(board, word, i, j+1, index+1);
    bool d=solve(board, word, i, j-1, index+1);
    board[i][j]=word[index];
    return a || b || c || d; // if any possible path exits
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    string word;
    cin>>word;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(solve(board, word, i, j, 0)){
                cout<<"Found"<<endl;
                return 0;
            }
        }
    }
    cout<<"Not Found"<<endl;
    return 0;
}