#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& graph, int index, vector<int>& visited){
    visited[index]=1;
    queue<pair<int, int>> q;
    q.push({index, -1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto x: graph[node]){
            if(!visited[x]){
                visited[x]=1;
                q.push({x, node});
            }
            else if(x!=parent){ // found any other visited node other than its parent
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> visited(n, 0);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(check(graph, i, visited)){
                return true;
            }
        }
    }
    return false;
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
    if(isCycle(graph)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}