#include<bits/stdc++.h>
using namespace std;

int largestPowerOf2(int n){
    int power=0;
    while((1<<power)<=n){
        power++;
    }
    return power-1;
}

int solve(int n){
    if(n==0){
        return 0;
    }
    int x=largestPowerOf2(n); // find largest power of 2 less than or equal to n
    int ans=x*(1<<(x-1)); // number of set bits from 0 to 2^x (not including) is x*(2^(x-1))
    ans+=(n-(1<<(x))+1);    // MSB is set for all bits from 2^x onwards
    ans+=solve(n-(1<<x)); // solve for remaing bits excluding their MSB
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=solve(n);
    cout<<ans<<endl;
    return 0;
}