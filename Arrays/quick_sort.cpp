#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int start, int end){
    int pivot=arr[end];
    int i=start-1;
    int j=start;
    while(j<end){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quick_sort(vector<int>& arr, int start, int end){
    if(start<end){
        int pivot=partition(arr, start, end);
        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quick_sort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}