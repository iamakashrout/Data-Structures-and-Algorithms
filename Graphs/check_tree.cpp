#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int parent){
    if(visited[node]==0){
        visited[node]=1;
        for(auto v: graph[node]){
            if(visited[v]==0){
                if(dfs(graph, visited, v, node)==0){ // cycle detected
                    return false;
                }
            }
            else if(visited[v]==1 && v!=parent && v!=-1){ // cycle detected as again visiting same node
                return false;
            }
        }
    }
    return true;
}

bool checkTree(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> visited(n, 0);
    if(dfs(graph, visited, 0, -1)==false){ // check if cycle exists, tree does not contain cycle
        return false;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0){ // see if all components are connected
            return false;
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
    if(checkTree(graph)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}