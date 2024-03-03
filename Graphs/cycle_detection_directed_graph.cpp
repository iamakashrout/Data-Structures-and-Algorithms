#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> inDegrees(n, 0); // no. of incoming edges
    for(int i=0; i<n; i++){
        for(int j=0; j<graph[i].size(); j++){
            inDegrees[graph[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegrees[i]==0){ // start with nodes with 0 incoming edges
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        count++;
        for(auto x: graph[curr]){
            inDegrees[x]--;
            if(inDegrees[x]==0){ // if all incoming edges encountered, then visit node
                q.push(x);
            }
        }
    }
    return count!=n; // if all nodes cannot be visited, then cycle exists
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