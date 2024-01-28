#include<bits/stdc++.h>
using namespace std;

bool anagram(string s1, string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    int n=s1.size();
    map<char, int> mp;
    for(int i=0; i<n; i++){
        mp[s1[i]]++;
    }
    for(int i=0; i<n; i++){
        mp[s2[i]]--;
        if(mp[s2[i]]==0){
            mp.erase(s2[i]);
        }
    }
    return mp.empty();
}

int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    cout<<anagram(s1, s2)<<endl;
    return 0;
}