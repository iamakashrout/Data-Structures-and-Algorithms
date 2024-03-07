#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    map<char, int> mp;
    for(int i=0; i<26; i++){
        char c='a'+i;
        mp[c]=-1; // stores last occurence of each character till now
    }
    int ans=0;
    int left=0;
    int right=0;
    while(right<s.size()){
        if(mp[s[right]]!=-1){
            left=max(left, mp[s[right]]+1); // if last occurence was greater than current start point, update start point
        }
        mp[s[right]]=right; // update last occurence of character
        ans=max(ans, right-left+1); // length of current substring
        right++;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans=solve(s);
    cout<<ans<<endl;
    return 0;
}