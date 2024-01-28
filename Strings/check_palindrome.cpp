#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int n=s.size();
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<palindrome(s)<<endl;
    return 0;
}