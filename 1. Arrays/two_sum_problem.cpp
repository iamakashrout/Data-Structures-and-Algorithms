#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& a, int k){
    int i=0, j=a.size()-1; // sorted array, use two pointers
    while(i<j){
        if(a[i]+a[j]>k){
            j--;
        }
        else if(a[i]+a[j]<k){
            i++;
        }
        else{
            return {a[i], a[j]};
        }
    }
    return {-1, -1};
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
    sort(a.begin(), a.end());
    vector<int> ans=twoSum(a, k);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}