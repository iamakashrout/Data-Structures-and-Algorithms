#include<bits/stdc++.h>
using namespace std;

// set all rows and columns to all 0s which have any value as 0
void setMatrixZeroes(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    bool flag1=false;
    for(int i=0; i<m; i++){ // mark if first column needs to be made 0
        if(matrix[i][0]==0){
            flag1=true;
            break;
        }
    }
    bool flag2=false;
    for(int i=0; i<n; i++){ // mark if first row needs to be made 0
        if(matrix[0][i]==0){
            flag2=true;
            break;
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]==0){ // find which all rows and columns need to be made 0
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){ // set requied rows and columns to 0
                matrix[i][j]=0;
            }
        }
    }
    if(flag1==true){ // check for 1st column
        for(int i=0; i<m; i++){
            matrix[i][0]=0;
        }
    }
    if(flag2==true){ // check for 1st row
        for(int j=0; j<n; j++){
            matrix[0][j]=0;
        }
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    setMatrixZeroes(matrix);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}