#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int>>& graph, vector<int>& topo){
    int n=graph.size();
    vector<int> inDegrees(n, 0);
    for(int i=0; i<graph.size(); i++){
        for(auto x: graph[i]){
            inDegrees[x]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegrees[i]==0){ // start with nodes with no prerequisites
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        topo.push_back(curr);
        for(auto x: graph[curr]){
            inDegrees[x]--;
            if(inDegrees[x]==0){ // visit node when all prerequisites are satisfied
                q.push(x);
            }
        }
    }
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
    vector<int> topo;
    topoSort(graph, topo);
    for(int i=0; i<topo.size(); i++){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
    return 0;
}