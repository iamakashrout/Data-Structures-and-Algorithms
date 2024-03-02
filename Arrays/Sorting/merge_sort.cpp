#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end){ // Merging two sorted halves
    vector<int> arr1(mid-start+1);
    vector<int> arr2(end-mid);
    for(int i=0; i<(mid-start+1); i++){
        arr1[i]=arr[i+start];
    }
    for(int i=0; i<(end-mid); i++){
        arr2[i]=arr[i+mid+1];
    }
    int i=0, j=0, k=start;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<arr1.size()){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<arr2.size()){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int start, int end){ // Partition into two halves and then merge
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}