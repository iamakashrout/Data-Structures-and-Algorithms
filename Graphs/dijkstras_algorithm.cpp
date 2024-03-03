#include<bits/stdc++.h>
using namespace std;

// finding shortest distance ti=o each vertex from node 'start'
vector<int> dijkstra(vector<vector<vector<int>>>& graph, int start){
    int n=graph.size();
    vector<int> dist(n, INT_MAX); // store distance of all vertices from start
    set<pair<int, int>> s; // contains the currently found shortest distance from start and the vertex no.
    // sorted in increasing order of distance
    dist[start]=0; // distance for start is 0
    s.insert({0, start});
    while(!s.empty()){
        auto curr=*(s.begin());
        int node=curr.second;
        int d=curr.first;
        s.erase(curr);
        for(auto x: graph[node]){
            int adjNode=x[0];
            int adjDist=x[1];
            if(dist[adjNode]>d+adjDist){ // if distance from current path is shorter, update distance
                s.erase({dist[adjNode], adjNode});
                dist[adjNode]=d+adjDist;
                s.insert({dist[adjNode], adjNode}); // explore paths from this node then
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
    int start;
    cin>>start;
    vector<int> ans=dijkstra(graph, start);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}