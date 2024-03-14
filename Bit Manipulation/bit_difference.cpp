#include<bits/stdc++.h>
using namespace std;

int bitDifference(int a, int b){
    int x=(a^b);
    // xor of a and b has 1 for every bit where a and b differ
    // so find number of set bits in a^b
    int ans=0;
    while(x>0){
        x=(x&(x-1));
        ans++;
    }
    return ans;
}

int main(){
    int a, b;
    cin>>a>>b;
    int ans=bitDifference(a, b);
    cout<<ans<<endl;
    return 0;
}