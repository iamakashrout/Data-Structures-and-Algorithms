#include<bits/stdc++.h>
using namespace std;

// element which occurs atleast n/2 times
int majorityElement(vector<int>& a){
    int n=a.size();
    int count=0; // count of majority element
    int element=0; // current element taken as majority element
    for(int i=0; i<n; i++){
        if(count==0){
            count=1;
            element=a[i];
        }
        else if(a[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    int c=0; // count of final majority element, it has to be >=n/2
    for(int i=0; i<n; i++){
        if(a[i]==element){
            c++;
        }
    }
    if(c>=n/2){
        return element;
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
    int ans=majorityElement(a);
    cout<<ans<<endl;
    return 0;
}