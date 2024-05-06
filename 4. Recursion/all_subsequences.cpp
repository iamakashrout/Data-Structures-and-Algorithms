#include<bits/stdc++.h>
using namespace std;

void allSubsequences(string s, int index, vector<string>& ans, string temp, map<string, bool>& check){
    if(index==s.size()){ // add to ans when last index has been checked
        if(check[temp]==true){
            return;
        }
        check[temp]=true;
        ans.push_back(temp);
        return;
    }
    allSubsequences(s, index+1, ans, temp+s[index], check); // take current char
    allSubsequences(s, index+1, ans, temp, check); // dont take current char
}

int main(){
    string s;
    cin>>s;
    vector<string> ans;
    map<string, bool> check;
    allSubsequences(s, 0, ans, "", check);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}