#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int>& st){
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st = temp;
}

void print(stack<int> st){
    if(st.empty()){
        return;
    }
    int x = st.top();
    st.pop();
    print(st);
    cout << x << " ";
    st.push(x);
}

int main(){
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    print(st);
    cout << endl;
    reverse(st);
    print(st);
    return 0;
}