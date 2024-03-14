#include<bits/stdc++.h>
using namespace std;

long long int divide(long long int a, long long int b){
    int sign=1;
    if((a>0 && b<0) || (a<0 && b>0)){ // handle sign
        sign=-1;
    }
    a=abs(a);
    b=abs(b);
    long long int quotient=0;
    long long int temp=0;
    // multiply divisor with decreasing powers of 2 until dividend is reached
    for(int i=31; i>=0; i--){
        if(temp+(b<<i)<=a){
            temp+=(b<<i);
            quotient+=(1<<i); // add 2^i to quotient
        }
    }
    if(sign==-1){
        quotient=-quotient;
    }
    return quotient;
}

int main(){
    long long int a, b;
    cin>>a>>b;
    long long int ans=divide(a, b);
    cout<<ans<<endl;
    return 0;
}