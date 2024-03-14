#include<bits/stdc++.h>
using namespace std;

int square(int n){
    if(n==0){
        return 0;
    }
    if(n<0){ // handling negative integers
        n=-n;
    }
    int x=n>>1;
    // if n is odd, => n=2*x+1 => n^2 = 4*(x^2)+1+4*x
    // if n is even, => n=2*x => n^2 = 4*(x^2)
    if(n&1){
        return ((square(x)<<2)+(x<<2)+1); // left shift by 2 means multiplying by 4
    }
    return (square(x)<<2);
}

int main(){
    int n;
    cin>>n;
    int ans=square(n);
    cout<<ans<<endl;
    return 0;
}