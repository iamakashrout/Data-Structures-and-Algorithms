#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        // match with last open bracket
        else if(!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}'))){
            st.pop();
        }
        else{
            return false; // if not matched, then not a valid parenthesis
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    if(validParenthesis(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}