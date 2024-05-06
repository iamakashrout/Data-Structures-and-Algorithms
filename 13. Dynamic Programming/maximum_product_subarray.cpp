#include<bits/stdc++.h>
using namespace std;

int MPS(vector<int>& a){
    int n=a.size();
    int smallest=a[0];
    int largest=a[0];
    int ans=a[0];
    for(int i=1; i<n; i++){
        int temp=max({a[i], largest*a[i], smallest*a[i]});
        // largest*a[i] handles positive a[i]
        // smallest*a[i] handles negative a[i]
        // a[i] handles 0 case
        smallest=min({a[i], largest*a[i], smallest*a[i]});
        largest=temp;
        ans=max(ans, largest);
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
    int ans=MPS(a);
    cout<<ans<<endl;
    return 0;
}