#include<bits/stdc++.h>
using namespace std;

// maximum number of consecutive ones that can be obtained after flipping k 0s
int solve(vector<int>& a, int k){
    int ans=0;
    int start=0; // start and end maintain the current window
    for(int end=0; end<a.size(); end++){
        if(a[end]==0){ // if 0, convert to 1, decrease 1
            k--;
        }
        while(k<0){
            if(a[start]==0){ // if number of 0s greater than k, remove 0s from front
                k++;
            }
            start++;
        }
        ans=max(ans, end-start+1); // compare current window of 1s with ans and update
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int ans=solve(a, k);
    cout<<ans<<endl;
    return 0;
}