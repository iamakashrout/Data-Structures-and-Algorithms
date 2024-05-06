#include<bits/stdc++.h>
using namespace std;

int matrixMedian(vector<vector<int>>& matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    int low=INT_MAX, high=INT_MIN;
    for(int i=0; i<r; i++){
        low=min(low, matrix[i][0]);
        high=max(high, matrix[i][c-1]);
    }
    int req=(r*c+1)/2;
    while(low<high){
        int mid=(low+high)/2;
        int count=0;
        for(int i=0; i<r; i++){
            int curr=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            // finding all smaller and equal elements to mid
            count+=curr;
        }
        if(req>count){ // if less than required number of smaller elements, then search on right
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}

int main(){
    int r;
    cin>>r;
    int c;
    cin>>c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>matrix[i][j];
        }
    }
    int ans=matrixMedian(matrix);
    cout<<ans<<endl;
    return 0;
}