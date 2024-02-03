#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans, int index){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(index>=nums.size() || target<0){
        return;
    }
    temp.push_back(nums[index]);
    solve(nums, target-nums[index], temp, ans, index);
    temp.pop_back();
    solve(nums, target, temp, ans, index+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(nums, target, temp, ans, 0);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}