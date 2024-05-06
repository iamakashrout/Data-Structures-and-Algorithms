#include<bits/stdc++.h>
using namespace std;

// Trie data structure to insert and search words

class Trie{
public:
    Trie* children[26]; // check if this character exits at current level
    bool wordEnd; // check if a word ending at this character is in the trie

    Trie(){ // constructor
        wordEnd=false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }

    void insert(string word){
        Trie* curr=this;
        for(auto ch: word){ // insert character at level and move to next level
            if(curr->children[ch-'a']==NULL){
                Trie* newNode=new Trie();
                curr->children[ch-'a']=newNode;
            }
            curr=curr->children[ch-'a'];
        }
        curr->wordEnd=true; // marking word ending as true
    }

    bool search(string word){
        Trie* curr=this;
        for(auto ch: word){
            if(curr->children[ch-'a']==NULL){ // if character at level not found, then word not in trie
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return curr->wordEnd==true; // check if word ends at last character
    }
};

int main(){
    Trie root;
    int ops;
    cin>>ops;
    for(int i=0; i<ops; i++){
        int op;
        cin>>op;
        if(op==1){
            string word;
            cin>>word;
            root.insert(word);
        }
        else if(op==2){
            string word;
            cin>>word;
            if(root.search(word)==true){
                cout<<"Found"<<endl;
            }
            else{
                cout<<"Not Found"<<endl;
            }
        }
    }
    return 0;
}