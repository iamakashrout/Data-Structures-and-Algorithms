#include<bits/stdc++.h>
using namespace std;

// return position of only set bit in number, return -1 if 0 or more than 1 set bits in number
int pos(int n){
    int ans=0;
    if(n==0 || (n&(n-1))!=0){
        return -1;
    }
    while(n>0){ // right shift till set bit is reached
        n=(n>>1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=pos(n);
    cout<<ans<<endl;
    return 0;
}