#include<bits/stdc++.h>
using namespace std;

// find first greater element of each index to the right of it in an array
vector<int> nextGreaterElement(vector<int>& a){
    stack<int> st;
    int n=a.size();
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=a[i]){ // remove all smaller elements ahead of current index
            st.pop();
        }
        if(st.empty()){ // if no greater element left
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(a[i]);
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
    vector<int> ans=nextGreaterElement(a);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}