#include<bits/stdc++.h>
using namespace std;

int jumpGame(vector<int>& a){
    int n=a.size();
    if(n==1){
        return 0;
    }
    if(a[0]==0){
        return -1;
    }
    int maxReach=a[0]; // maximum position that can be reached currently
    int steps=a[0]; // position from previous jump point
    int jumps=1; // number of jumps taken
    for(int i=1; i<n; i++){
        if(i==n-1){
            return jumps;
        }
        maxReach=max(maxReach, i+a[i]);
        steps--;
        if(steps==0){ // if last possible position reached, make jump which leads to largest increase
            jumps++;
            if(i>=maxReach){
                return -1;
            }
            steps=maxReach-i;
        }
    }
    return jumps;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=jumpGame(a);
    cout<<ans<<endl;
    return 0;
}