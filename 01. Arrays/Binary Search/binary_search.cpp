#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int k){
    int low=0, high=a.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(a[mid]>k){
            high=mid-1;
        }
        else if(a[mid]<k){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
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
    int ans=binarySearch(a, k);
    cout<<ans<<endl;
    return 0;
}