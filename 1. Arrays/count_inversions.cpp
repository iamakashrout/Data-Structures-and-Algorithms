#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int start, int mid, int end, int& ans){
    vector<int> temp(end-start+1);
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(a[i]>a[j]){
            ans+=(mid-i+1); // check how many positions the number is away from its actual position
            temp[k]=a[j];
            j++;
        }
        else{
            temp[k]=a[i];
            i++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k]=a[j];
        j++;
        k++;
    }
    for(int i=start; i<=end; i++){
        a[i]=temp[i-start];
    }
}

void mergeSort(vector<int>& a, int start, int end, int& ans){
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(a, start, mid, ans);
        mergeSort(a, mid+1, end, ans);
        merge(a, start, mid, end, ans);
    }
}

int countInversions(vector<int>& a){
    int ans=0;
    mergeSort(a, 0, a.size()-1, ans); // apply merge sort
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=countInversions(a);
    cout<<ans<<endl;
    return 0;
}