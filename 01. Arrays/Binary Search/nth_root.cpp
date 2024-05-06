#include<bits/stdc++.h>
using namespace std;

int check(int x, int num, int n){
    int ans=1;
    for(int i=1; i<=n; i++){
        ans=ans*x;
        if(ans>num){
            return 2; // x is greater than nth root
        }
    }
    if(ans==num){
        return 1; // x is the nth root
    }
    return 0; // x is less than the nth root
}

int nthRoot(int num, int n){
    int low=1, high=num;
    while(low<=high){
        int mid=(low+high)/2;
        int x=check(mid, num, n); // check result for mid
        if(x==1){
            return mid;
        }
        else if(x==2){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int num;
    cin>>num;
    int n;
    cin>>n;
    int ans=nthRoot(num, n);
    cout<<ans<<endl;
    return 0;
}