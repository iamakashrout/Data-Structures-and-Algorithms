#include<bits/stdc++.h>
using namespace std;

void subsequences(string s, string& temp, int index, vector<string>& ans){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    temp=temp+s[index];
    subsequences(s, temp, index+1, ans);
    temp.pop_back();
    subsequences(s, temp, index+1, ans);
}

int main(){
    string s;
    cin>>s;
    string temp="";
    vector<string> ans;
    subsequences(s, temp, 0, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}