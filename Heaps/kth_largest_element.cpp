#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& a, int k){
    int n=a.size();
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(a[i]);
        if(pq.size()>n-k+1){ // remove largest k-1 elements from pq
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int ans=kthLargest(a, k);
    cout<<ans<<endl;
    return 0;
}