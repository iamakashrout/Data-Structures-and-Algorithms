#include<bits/stdc++.h>
using namespace std;

// Rabin Karp Algorithm for Pattern Matching

bool rabin_karp(string s, string p){
    int n=s.size();
    int m=p.size();
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<m; j++){
            if(s[i+j]!=p[j]){
                break;
            }
            if(j==m-1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    string p;
    cin>>p;
    cout<<rabin_karp(s, p)<<endl;
    return 0;
}