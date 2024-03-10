#include<bits/stdc++.h>
using namespace std;

void allPermutations(string s, int l, int r, vector<string>& ans, map<string, bool>& check){
    if(l==r){
        if(check[s]==true){
            return;
        }
        check[s]=true;
        ans.push_back(s);
        return;
    }
    for(int i=l; i<=r; i++){
        swap(s[i], s[l]); // select first character
        allPermutations(s, l+1, r, ans, check); // find permutations for other places
        swap(s[i], s[l]); // repeat by taking every character as first
    }
}

int main(){
    string s;
    cin>>s;
    vector<string> ans;
    map<string, bool> check;
    allPermutations(s, 0, s.size()-1, ans, check);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}