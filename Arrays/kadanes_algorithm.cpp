#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorith for Maximum Sum Subarray
int maxSum(vector<int>& a){
    int n=a.size();
    int ans=a[0];
    int sum=a[0];
    for(int i=1; i<n; i++){
        if(sum<0){
            sum=0; // if sum of previous elements is negative, discard it
        }
        sum+=a[i];
        ans=max(ans, sum);
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
    int ans=maxSum(a);
    cout<<ans<<endl;
    return 0;
}