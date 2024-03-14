#include<bits/stdc++.h>
using namespace std;

// 2*n+2 elements out of which n repeat 2 times and 2 occur only once, find the 2 non-repeating numbers
vector<int> solve(vector<int>& a){
    int n=a.size();
    int xorAll=0;
    for(int i=0; i<n; i++){
        xorAll=(xorAll^a[i]); // all repeating numbers get cancelled, xor of two non-repeating elements is left
    }
    int rightMostSetBit=(xorAll&(~(xorAll-1))); // find rightmost set bit in xor
    // first point of bit difference between the two numbers
    int oneBits=0; // for all numbers having 1 at this bit
    int zeroBits=0; // for all numbers having 0 at this bit
    for(int i=0; i<n; i++){
        if(a[i]&rightMostSetBit){
            oneBits=(oneBits^a[i]); // repeating elements get cancelled and non-repeating element with 1 is left
        }
        else{
            zeroBits=(zeroBits^a[i]); // non-repeating element with 0 is left
        }
    }
    vector<int> ans;
    // add the numbers to answer
    ans.push_back(zeroBits);
    ans.push_back(oneBits);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(2*n+2);
    for(int i=0; i<(2*n+2); i++){
        cin>>a[i];
    }
    vector<int> ans=solve(a);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}