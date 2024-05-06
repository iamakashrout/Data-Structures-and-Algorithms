#include<bits/stdc++.h>
using namespace std;

// given x and y, convert all set bits in y from range l to r to set bits in x
int solve(int x, int y, int l, int r){
    int mask=(1<<(r-l+1)); // shift 1 so that mask has (r-l+1) zeros
    mask--; // now mask has (r-l+1) ones
    mask=(mask<<(l-1)); // shift these ones to required position
    mask=(mask&y); // only set bits in y remain set in mask
    x=(x|mask); // set bits in mask also make those bits in x set
    return x;
}

int main(){
    int x, y, l, r;
    cin>>x>>y>>l>>r;
    int ans=solve(x, y, l, r);
    cout<<ans<<endl;
    return 0;
}