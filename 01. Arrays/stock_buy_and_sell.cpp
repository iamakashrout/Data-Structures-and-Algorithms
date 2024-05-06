#include<bits/stdc++.h>
using namespace std;

int stocks(vector<int>& v){
    int n=v.size();
    int buy=INT_MAX; // minimum price of buying stock
    int sell=0; // maximum difference of selling price and buying price
    for(int i=0; i<n; i++){
        sell=max(sell, v[i]-buy); // update max profit
        buy=min(buy, v[i]); // update min buy
    }
    return sell;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int ans=stocks(v);
    cout<<ans<<endl;
    return 0;
}