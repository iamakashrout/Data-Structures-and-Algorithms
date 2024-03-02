#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a){
    int n=a.size();
    vector<int> lis;
    lis.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i]>lis.back()){
            lis.push_back(a[i]); // if greater than last element, add to LIS
        }
        else{
            int index=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin(); // replace next larger element in LIS with a[i]
            lis[index]=a[i];
        }
    }
    return lis.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=LIS(a);
    cout<<ans<<endl;
    return 0;
}