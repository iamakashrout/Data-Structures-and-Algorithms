#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& st, int x){
    if(st.empty() || st.top()<=x){ // if last element greater than top, then push
        st.push(x);
        return;
    }
    int y=st.top();
    st.pop(); // else go to correct position and then push
    sortedInsert(st, x);
    st.push(y);
}

void sortStack(stack<int>& st){
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    sortStack(st); // recursively sort remaining stack and then push last element such that stack remains sorted
    sortedInsert(st, x);
}

int main(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    sortStack(st);
    stack<int> temp=st;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
    return 0;
}