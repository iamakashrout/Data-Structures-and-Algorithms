#include<bits/stdc++.h>
using namespace std;

bool rotation(string s1, string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    int n=s1.size();
    queue<char> q1;
    for(int i=0; i<n; i++){
        q1.push(s1[i]);
    }
    queue<char> q2;
    for(int i=0; i<n; i++){
        q2.push(s2[i]);
    }
    while(n--){
        char c=q2.front();
        q2.pop();
        q2.push(c);
        if(q1==q2){
            return true;
        }
    }
    return false;
}

int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    cout<<rotation(s1, s2);
    return 0;
}