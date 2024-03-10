#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){ // check palindrome function
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(string s, vector<vector<string>>& ans, int index, vector<string>& temp){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){ // first palindrome part
            temp.push_back(s.substr(index, i-index+1));
            solve(s, ans, i+1, temp); // solve for rest
            temp.pop_back();
        }
    }
}

int main(){
    string s;
    cin>>s;
    vector<vector<string>> ans;
    vector<string> temp;
    solve(s, ans, 0, temp);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}