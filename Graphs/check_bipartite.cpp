#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> section(n, 0);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(section[i]!=0){
            continue;
        }
        // check for all uncoloured nodes
        section[i]=1; // colour it to A
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto x: graph[curr]){
                if(section[x]==0){
                    section[x]=-section[curr]; // colour all neighbours in opposite colour
                    q.push(x);
                }
                else if(section[x]==section[curr]){ // if neighbour has same colour, then not bipartite
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n); // adjacency list representation
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        for(int j=0; j<x; j++){
            int v;
            cin>>v;
            graph[i].push_back(v);
        }
    }
    if(bipartite(graph)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}