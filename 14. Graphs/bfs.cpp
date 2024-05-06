#include<bits/stdc++.h>
using namespace std;

// BREADTH FIRST SEARCH
void BFS(vector<vector<int>>& graph, vector<int>& bfs){
    int n=graph.size();
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        bfs.push_back(curr);
        for(int i=0; i<graph[curr].size(); i++){
            if(!visited[graph[curr][i]]){
                visited[graph[curr][i]]=1;
                q.push(graph[curr][i]);
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
    vector<int> bfs;
    BFS(graph, bfs);
    for(int i=0; i<bfs.size(); i++){
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}