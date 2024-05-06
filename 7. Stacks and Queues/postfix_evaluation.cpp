#include<bits/stdc++.h>
using namespace std;

int postfix(string s){
    stack<int> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){ // if digit, push to stack
            st.push(s[i]-'0');
        }
        else{
            // if operator, pop last two digits and push their result to stack
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(s[i]=='+'){
                st.push(b+a);
            }
            else if(s[i]=='-'){
                st.push(b-a);
            }
            else if(s[i]=='*'){
                st.push(b*a);
            }
            else if(s[i]=='/'){
                st.push(b/a);
            }
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    int ans=postfix(s);
    cout<<ans<<endl;
    return 0;
}