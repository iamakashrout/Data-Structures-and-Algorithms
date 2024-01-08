#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr){ // Smallest element to front
    for(int i=0; i<arr.size()-1; i++){
        int min_idx=i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selection_sort(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}