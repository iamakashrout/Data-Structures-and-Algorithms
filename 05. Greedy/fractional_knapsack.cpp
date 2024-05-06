#include<bits/stdc++.h>
using namespace std;

// items can be divided into fractions

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> items(n);
    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second;
    }
    int w;
    cin>>w;
    // sort according to value/weight ratio
    sort(items.begin(), items.end(), [](pair<int, int>& a, pair<int, int>& b){
        return (double)a.first/a.second>(double)b.first/b.second;
    });
    int rem=w;
    double ans=0;
    for(int i=0; i<n; i++){
        if(rem>=items[i].second){
            rem-=items[i].second;
            ans+=items[i].first;
        }
        else{
            ans+=(double)items[i].first*rem/items[i].second;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}