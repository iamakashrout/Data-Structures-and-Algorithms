#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie* children[26];
    bool wordEnd;
    int count=0; // no. of words having this prefix
};

void insert(Trie* root, string word){
    Trie* temp=root;
    for(int i=0; i<word.size(); i++){
        int index=word[i]-'a';
        if(temp->children[index]!=NULL){
            temp=temp->children[index];
            temp->count++; // increase count of this prefix
        }
        else{
            temp->children[index]=new Trie();
            temp=temp->children[index];
            temp->count=1;
        }
    }
    temp->wordEnd=true;
    return;
}

string search(Trie* root, string word){
    Trie* temp=root;
    int i=0;
    while(i<word.size()){
        if(temp->children[word[i]-'a']!=NULL){
            temp=temp->children[word[i]-'a'];
            if(temp->count==1){ // if only one word has this prefix, then return as answer
                break;
            }
        }
        else{
            return ""; // if string not present in trie
        }
        i++;
    }
    return word.substr(0, i+1);
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    Trie* root=new Trie();
    for(int i=0; i<n; i++){
        insert(root, v[i]);
    }
    vector<string> ans;
    for(int i=0; i<n; i++){
        string curr=search(root, v[i]);
        ans.push_back(curr);
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}