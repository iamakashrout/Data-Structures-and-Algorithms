#include<bits/stdc++.h>
using namespace std;

vector<string> permutations(string s){
    int n=s.size();
    vector<string> ans;
    if(n==1){
        ans.push_back(s);
        return ans;
    }
    sort(s.begin(), s.end());
    for(int i=0; i<n; i++){
        if(i>0 && s[i]==s[0]){
            continue;
        }
        char c=s[0];
        s[0]=s[i];
        s[i]=c;
        vector<string> temp=permutations(s.substr(1));
        for(int j=0; j<temp.size(); j++){
            string curr=s[0]+temp[j];
            ans.push_back(curr);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> perms=permutations(s);
    for(int i=0; i<perms.size(); i++){
        cout<<perms[i]<<endl;
    }
    return 0;
}