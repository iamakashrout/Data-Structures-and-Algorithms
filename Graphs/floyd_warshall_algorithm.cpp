#include<bits/stdc++.h>
using namespace std;

// finding shortest distance between every pair of nodes
void FWA(vector<vector<int>>& graph){
    int n=graph.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]==-1){
                graph[i][j]=1e8;
            }
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // check path path through node k results in shorter overall distance and update
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]==1e8){
                graph[i][j]=-1;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n, vector<int>(n)); // adjacency matrix representation
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    FWA(graph);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}