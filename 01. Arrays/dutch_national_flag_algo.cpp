#include<bits/stdc++.h>
using namespace std;

// sort an array having only 0, 1 ans 2s (Dutch National Flag Algorithm)

void sort012(vector<int>& a){
    int l=0, r=a.size()-1;
    int i=0;
    while(i<=r){
        if(a[i]==0){
            swap(a[i], a[l]); // if 0, send to start pointer
            l++;
            i++;
        }
        else if(a[i]==2){ // if 2, send to end pointer
            swap(a[i], a[r]);
            r--;
        }
        else{ // else continue current pointer
            i++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort012(a);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}