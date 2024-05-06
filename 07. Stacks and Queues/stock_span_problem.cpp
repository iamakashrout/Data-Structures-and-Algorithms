#include<bits/stdc++.h>
using namespace std;

// number of consecutive smaller values less than current index
vector<int> stockSpan(vector<int>& a){
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() && a[st.top()]<=a[i]){ // find last greater element
            st.pop();
        }
        if(!st.empty()){
            ans.push_back(i-st.top()); // number of elements after last greater element is the required value
        }
        else{
            ans.push_back(i+1);
        }
        st.push(i);
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
    vector<int> ans=stockSpan(a);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}