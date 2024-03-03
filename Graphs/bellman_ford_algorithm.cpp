#include<bits/stdc++.h>
using namespace std;

// shortest distance to each node from node 'start' accounting for negative cycles
vector<int> BFA(vector<vector<int>>& edges, int start, int n){
    vector<int> dist(n, 1e8);
    dist[start]=0;
    for(int i=0; i<n-1; i++){
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){ // update distance to v through u
                dist[v]=dist[u]+w;
            }
        }
    }
    for(auto e: edges){
        int u=e[0];
        int v=e[1];
        int w=e[2];
        if(dist[u]!=1e8 && dist[u]+w<dist[v]){ // check negative cycle
            return {-1}; // if negative cycle exists, retun no answer
        }
    }
    return dist;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> edges(e, vector<int>(3)); // weighted edge list representation
    for(int i=0; i<e; i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    int start;
    cin>>start;
    vector<int> ans=BFA(edges, start, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}