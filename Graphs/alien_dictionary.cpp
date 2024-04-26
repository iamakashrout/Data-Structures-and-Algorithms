#include<bits/stdc++.h>
using namespace std;

// given a set of words in lexicographical order according to an alien language having 1st k letters as alphabet
// find the order of letters in the alien alphabet

string findOrder(vector<string>& words, int k){
    int n=words.size();
    vector<vector<int>> graph(k); // maintains all letters which come after the given letter
    vector<int> inDegrees(k, 0); // number of letters coming before the given letter
    // using concept of topological sorting
    for(int i=0; i<n-1; i++){
        string s1=words[i];
        string s2=words[i+1];
        for(int j=0; j<min(s1.size(), s2.size()); j++){
            if(s1[j]!=s2[j]){
                // find point of difference and add to graph and indegrees
                graph[s1[j]-'a'].push_back(s2[j]-'a');
                inDegrees[s2[j]-'a']++;
                break;
            }
        }
    }
    queue<int> q;
    for(int i=0; i<k; i++){
        if(inDegrees[i]==0){ // all letters having no dependencies
            q.push(i);
        }
    }
    string ans="";
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans+=(curr+'a');
        for(int i: graph[curr]){ // all letters coming after given letter
            inDegrees[i]--;
            if(inDegrees[i]==0){ // add to queue if all dependencies satisfied
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){
    int n, k; // n: no. of words, k: no. of alphabets in language
    cin>>n>>k;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin>>words[i];
    }
    string ans=findOrder(words, k);
    cout<<ans<<endl;
    return 0;
}