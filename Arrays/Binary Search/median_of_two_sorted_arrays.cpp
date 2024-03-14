#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b){
    int m=a.size();
    int n=b.size();
    if(m>n){
        return median(b, a);
    }
    // cut the smaller array first and then the larger one accordingly
    int low=0, high=m;
    int medianPos=(m+n+1)/2; // number of elements to be taken on left side
    while(low<=high){
        int cut1=(low+high)/2; // position where array 1 is cut
        int cut2=medianPos-cut1; // position where array 2 is cut
        int l1, l2, r1, r2;
        // last element of left part of array 1
        if(cut1==0){
            l1=INT_MIN;
        }
        else{
            l1=a[cut1-1];
        }
        // last element of left part of array 2
        if(cut2==0){
            l2=INT_MIN;
        }
        else{
            l2=b[cut2-1];
        }
        // first element of right part of array 1
        if(cut1==m){
            r1=INT_MAX;
        }
        else{
            r1=a[cut1];
        }
        // first element of right part of array 2
        if(cut2==n){
            r2=INT_MAX;
        }
        else{
            r2=b[cut2];
        }
        // for finding median, last element from left of array 1 should be less than first element from right of array 2
        // and last element from left of array 2 should be less than first element from right of array 1
        if(l1<=r2 && l2<=r1){
            if((m+n)%2!=0){
                return max(l1, l2); // take largest from left in case of odd total count
            }
            else{
                // else take average of largest from left and smallest from right
                return (max(l1, l2)+min(r1, r2))/2.0;
            }
        }
        else if(l1>r2){ // if last left element of array 1 is greater than first right element of array 2
            high=cut1-1; // cut array 1 at a lesser index
        }
        else{
            low=cut1+1; // else cut array 1 at a higher index
        }
    }
    return 0.0;
}

int main(){
    int m;
    cin>>m;
    vector<int> a(m);
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    double ans=median(a, b);
    cout<<ans<<endl;
    return 0;
}