#include<bits/stdc++.h>
using namespace std;

// MINIMUM SPANNING TREE
bool unionFind(vector<int>& parent, int start, int end){
    // checks parents of components of two vertices
    int i=start;
    int j=end;
    while(i!=parent[i]){
        i=parent[i];
    }
    while(j!=parent[j]){
        j=parent[j];
    }
    if(i==j){
        return false;
    }
    parent[j]=i; // merge components if different
    return true;
}

int kruskal(vector<vector<vector<int>>>& graph){
    int n=graph.size();
    vector<vector<int>> edges; // make weighted list of all edges
    for(int i=0; i<n; i++){
        for(auto x: graph[i]){
            vector<int> v;
            v.push_back(x[1]);
            v.push_back(i);
            v.push_back(x[0]);
            edges.push_back(v);
        }
    }
    sort(edges.begin(), edges.end()); // sort edges in increasing order of weights
    int sum=0;
    vector<int> parent(n); // stores parent of the component in which each vertex lies
    for(int i=0; i<n; i++){
        parent[i]=i; // initially every vertex is its own component
    }
    int i=0;
    int count=0; // no. of edges taken so far, MST has n-1 edges
    while(count<n-1){
        if(unionFind(parent, edges[i][1], edges[i][2])==true){ // check if vertices belong to different components
            sum+=edges[i][0]; // if yes, then add to MST and merge those components
            count++;
        }
        i++;
    }
    return sum;
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
    int ans=kruskal(graph);
    cout<<ans<<endl;
    return 0;
}