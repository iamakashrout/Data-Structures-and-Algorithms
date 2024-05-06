#include<bits/stdc++.h>
using namespace std;

// largest area of rectangle formed by the bars of given histogram
int solve(vector<int>& heights){
    int n=heights.size();
    stack<int> leftStack;
    vector<int> left;
    // find last element to the left of current index with lower height
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
    // find next element to the right of current index with lower heights
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
    // for every index, calculate area that can be obtained by taking its height as height of rectangle
    // all bars to the left and right with >= height can be taken as part of rectangle's width
    for(int i=0; i<n; i++){
        int area=heights[i]*(right[i]-left[i]+1);
        ans=max(ans, area);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }
    int ans=solve(heights);
    cout<<ans<<endl;
    return 0;
}