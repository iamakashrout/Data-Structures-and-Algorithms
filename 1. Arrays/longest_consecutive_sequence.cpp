#include<bits/stdc++.h>
using namespace std;

// longest sequence of consecutive numbers that can be formed from elements of array
int solve(vector<int>& a){
    set<int> s;
    for(int i=0; i<a.size(); i++){
        s.insert(a[i]);
    }
    int ans=0;
    for(int i=0; i<a.size(); i++){
        if(!s.count(a[i]-1)){ // check if current number not part of any previous sequence
            int x=a[i];
            int curr=1;
            while(s.count(x+1)){ // find longest sequence possible from current number as starting point
                curr++;
                x++;
            }
            ans=max(ans, curr);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=solve(a);
    cout<<ans<<endl;
    return 0;
}