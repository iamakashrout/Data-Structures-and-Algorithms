#include<bits/stdc++.h>
using namespace std;


// MINIMUM SPANNING TREE
int prim(vector<vector<vector<int>>>& graph){
    int n=graph.size();
    set<pair<int, int>> s; // stores nearest distance from current MST and vertex no. of all edges of current vertices
    // stores vertices in increasing order of distance
    s.insert({0, 0}); // start from vertex 0
    int dist=0;
    vector<int> visited(n, 0);
    visited[0]=1;
    while(!s.empty()){
        auto x=*(s.begin());
        int node=x.second;
        int d=x.first;
        s.erase(s.begin());
        if(!visited[node]){
            dist+=d; // add distance of vertex to total MST size
        }
        visited[node]=1;
        for(auto x: graph[node]){ // check for all neigbours of current vertex
            int adjNode=x[0];
            int adjDist=x[1];
            if(!visited[adjNode]){ // if node not visited, add to set
                s.insert({adjDist, adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int n;
    cin>>n;
    vector<vector<vector<int>>> graph(n); // adjacency list representation with weight
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        for(int j=0; j<x; j++){
            int v, w;
            cin>>v>>w;
            graph[i].push_back({v, w});
        }
    }
    int ans=prim(graph);
    cout<<ans<<endl;
    return 0;
}