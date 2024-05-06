#include<bits/stdc++.h>
using namespace std;

// maximum rainwater that can be collected between bars of given heights
int solve(vector<int>& heights){
    int n=heights.size();
    int left=0, right=n-1; // left and right pointers, initially at ends
    int leftMax=0; // maximum bar to the left
    int rightMax=0; // maximum bar to the right
    // each bar stores water equal to the difference betweens its height and the minimum of its leftMax and rightMax
    int ans=0;
    while(left<=right){
        if(heights[left]<=heights[right]){ // if left pointer has lower height, add its water to answer
            leftMax=max(leftMax, heights[left]); // update leftMax
            ans+=(leftMax-heights[left]);
            left++;
        }
        else{ // else check for right pointer
            rightMax=max(rightMax, heights[right]); // update rightMax
            ans+=(rightMax-heights[right]);
            right--;
        }
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