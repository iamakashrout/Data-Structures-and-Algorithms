#include<bits/stdc++.h>
using namespace std;

// maximum area of rectangles having only 1s in a matrix

int solve(vector<int>& heights){
    int n=heights.size();
    stack<int> leftStack;
    vector<int> left;
    // for each column, find its first smaller height on left and first smaller height on right
    for(int i=0; i<n; i++){
        while(!leftStack.empty() && heights[leftStack.top()]>=heights[i]){
            leftStack.pop();
        }
        if(leftStack.empty()){
            left.push_back(0);
        }
        else{
            left.push_back(leftStack.top()+1);
        }
        leftStack.push(i);
    }
    stack<int> rightStack;
    vector<int> right;
    for(int i=n-1; i>=0; i--){
        while(!rightStack.empty() && heights[rightStack.top()]>=heights[i]){
            rightStack.pop();
        }
        if(rightStack.empty()){
            right.push_back(n-1);
        }
        else{
            right.push_back(rightStack.top()-1);
        }
        rightStack.push(i);
    }
    reverse(right.begin(), right.end());
    int ans=0;
    // find areas taking each column and find max
    for(int i=0; i<n; i++){
        int area=heights[i]*(right[i]-left[i]+1);
        ans=max(ans, area);
    }
    return ans;
}

int maxArea(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> heights(n, 0); // height of only 1s above current row
    int ans=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==1){ // increment 1 to height
                heights[j]++;
            }
            else{ // else height of 1s above current row is 0
                heights[j]=0;
            }
        }
        int area=solve(heights); // find area for each row and set max as answer
        ans=max(ans, area);
    }
    return ans;
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
    int ans=maxArea(matrix);
    cout<<ans<<endl;
    return 0;
}