#include<bits/stdc++.h>
using namespace std;


// DEPTH FIRST SEARCH
void DFS(int index, vector<vector<int>>& graph, vector<int>& visited, vector<int>& dfs){
    visited[index]=1;
    dfs.push_back(index);
    for(int i=0; i<graph[index].size(); i++){
        if(!visited[graph[index][i]]){
            DFS(graph[index][i], graph, visited, dfs);
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
    vector<int> visited(n, 0);
    vector<int> dfs;
    DFS(0, graph, visited, dfs);
    for(int i=0; i<dfs.size(); i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}