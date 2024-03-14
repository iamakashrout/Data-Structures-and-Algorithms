#include<bits/stdc++.h>
using namespace std;

bool powerOf2(int n){
    if(n==0){
        return 0;
    }
    // MSB of power of 2 is 1 and rest bits are 0, MSB of one less than power of 2 is 0 and rest bits are 1
    // so AND should be 0
    return (n&(n-1))==0;
}

int main(){
    int n;
    cin>>n;
    if(powerOf2(n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}