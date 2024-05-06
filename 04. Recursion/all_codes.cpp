#include<bits/stdc++.h>
using namespace std;

// all strings that can be formed by number code where 1->a, 2->b, ..., 26->z
void allCodes(string s, vector<string>& ans, int index, string temp){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    char c1=(s[index]-48)+96; // convert first digit to char
    if(s[index]=='0'){
        return;
    }
    allCodes(s, ans, index+1, temp+c1); // solve for rest of string
    if(index<s.size()-1){
        int x=(s[index]-48)*10+s[index+1]-48; // check if first two digits can be converted to char
        if(x>26){
            return;
        }
        char c2=x+96;
        allCodes(s, ans, index+2, temp+c2); // solve by taking first two digits as one char
    }
}

int main(){
    string s;
    cin>>s;
    vector<string> ans;
    allCodes(s, ans, 0, "");
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}