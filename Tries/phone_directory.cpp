#include<bits/stdc++.h>
using namespace std;

// find all words in directory starting with a given prefix

class Trie{
public:
    Trie* children[26];
    bool wordEnd;
    vector<int> index; // indices of words having this prefix
    Trie(){
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        wordEnd=false;
    }
};

void insert(Trie* root, string word, int i){
    Trie* curr=root;
    for(auto ch: word){
        int index=ch-'a';
        if(curr->children[index]==NULL){
            curr->children[index]=new Trie();
        }
        curr=curr->children[index];
        curr->index.push_back(i); // add index of word to this prefix
    }
    curr->wordEnd=true;
}

void helper(Trie* root, string temp, vector<vector<string>>& ans, vector<string>& contacts){
    Trie* curr=root;
    for(auto ch: temp){
        int index=ch-'a';
        if(curr->children[index]==NULL){ // if prefix does not exist in any word
            ans.push_back({"0"});
            return;
        }
        curr=curr->children[index];
    }
    set<string> s;
    for(auto i: curr->index){ // set has all unique words having current prefix
        s.insert(contacts[i]);
    }
    if(s.size()==0){ // if no word with this prefix exists
        ans.push_back({"0"});
    }
    else{
        vector<string> v;
        for(auto it: s){
            v.push_back(it);
        }
        ans.push_back(v); // add to answer
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> contacts(n);
    for(int i=0; i<n; i++){
        cin>>contacts[i];
    }
    string s;
    cin>>s;
    Trie* root=new Trie();
    for(int i=0; i<n; i++){
        insert(root, contacts[i], i);
    }
    vector<vector<string>> ans;
    string temp="";
    for(int i=0; i<s.size(); i++){ // add each character of string step by step and check answer
        temp+=s[i];
        helper(root, temp, ans, contacts);
    }
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}