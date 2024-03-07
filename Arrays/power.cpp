#include<bits/stdc++.h>
using namespace std;

int power(int base, int exponent){
    int ans=1;
    while(exponent>0){
        if(exponent%2==1){
            ans=ans*base;
            exponent--;
        }
        else{
            // x^y=(x^2)^(y/2) for even y
            base=base*base;
            exponent/=2;
        }
    }
    return ans;
}

int main(){
    int base;
    cin>>base;
    int exponent;
    cin>>exponent;
    int ans=power(base, exponent);
    cout<<ans<<endl;
    return 0;
}