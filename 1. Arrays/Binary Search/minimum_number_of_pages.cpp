#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int n, int m, int x){
    int count=1;
    int sum=0;
    for(int i=0; i<n; i++){
        if(sum+a[i]<=x){
            sum+=a[i];
        }
        else{
            count++;
            if(count>m || a[i]>x){
                return false;
            }
            sum=a[i];
        }
    }
    return true;
}

int solve(vector<int>& a, int m){
    int n=a.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    int ans=-1;
    int low=0, high=sum;
    if(n<m){
        return ans;
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(check(a, n, m, mid)){ // if mid can be the maximum limit, if yes then search for lower values
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1; // else search for higher values
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
    int m;
    cin>>m;
    int ans=solve(a, m);
    cout<<ans<<endl;
    return 0;
}