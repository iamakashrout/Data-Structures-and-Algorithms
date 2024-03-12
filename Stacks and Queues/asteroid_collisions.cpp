#include<bits/stdc++.h>
using namespace std;

vector<int> asteroids(vector<int>& a){
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        if(a[i]>0){
            st.push(a[i]);
        }
        else{
            // if asteroid moving to left, destroy all asteroids smaller and moving to right
            while(!st.empty() && st.top()>0 && st.top()<abs(a[i])){
                st.pop();
            }
            // if equal size, destroy both
            if(!st.empty() && st.top()>0 && st.top()==abs(a[i])){
                st.pop();
            }
            // if stack empty or remaining are moving left, add to stack
            else{
                if(st.empty() || st.top()<0){
                    st.push(a[i]);
                }
            }
        }
    }
    // add all remaining asteroids to the answer
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> ans=asteroids(a);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}