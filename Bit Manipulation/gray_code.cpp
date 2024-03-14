#include<bits/stdc++.h>
using namespace std;

// numbers of 0 to 2^n-1 such that consecutive numbers differ by exactly 1 bit
vector<int> grayCode(int n){
    if(n==1){
        return {0, 1}; // base case
    }
    vector<int> prev=grayCode(n-1); // find for n-1
    vector<int> ans;
    // add answer for n-1 first in original order with 0 as MSB
    // then add answer for n-1 in reverse order with 1 as MSB
    for(int i=0; i<prev.size(); i++){
        ans.push_back(prev[i]);
    }
    int msb=(1<<(n-1)); // set MSB to 1
    for(int i=n-1; i>=0; i--){
        ans.push_back(msb+prev[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans=grayCode(n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}