#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int ans=0;
    // for every set bit from rightmost side, ANDing with its previous number makes all digit from that bit onwards 0
    // this operation can be done for all set bits
    while(n>0){
        n=(n&(n-1));
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=countSetBits(n);
    cout<<ans<<endl;
    return 0;
}