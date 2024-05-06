#include<bits/stdc++.h>
using namespace std;

vector<string> powerSet(string s){
    vector<string> ans;
    int len=s.size();
    int n=(1<<len); // size of power set
    for(int i=1; i<n; i++){
        // for all values from 1 to n-1, include the characters with set bit in string
        string temp="";
        for(int j=0; j<len; j++){
            if(i&(1<<j)){
                temp+=s[j];

            }
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans=powerSet(s);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}