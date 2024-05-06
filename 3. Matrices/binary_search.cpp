#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>>& matrix, int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int start=0, end=m*n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(matrix[mid/n][mid%n]>target){
            end=mid-1;
        }
        else if(matrix[mid/n][mid%n]<target){
            start=mid+1;
        }
        else{
            return true;
        }
    }
    return false;
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
    int target;
    cin>>target;
    cout<<search(matrix, target)<<endl;
    return 0;
}