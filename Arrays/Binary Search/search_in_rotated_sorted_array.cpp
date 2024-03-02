#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int num){
    int n=a.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==num){
            return mid;
        }
        else if(a[low]<=a[mid]){
            if(num>=a[low] && num<a[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(num>a[mid] && num<=a[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
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
    int num;
    cin>>num;
    int ans=search(a, num);
    cout<<ans<<endl;
    return 0;
}