#include<bits/stdc++.h>
using namespace std;

// color all nodes using m colors such that no two adjacent nodes have same color
bool isSafe(vector<vector<int>>& graph, vector<int>& color, int n, int index, int i){
    for(int j=0; j<n; j++){
        // if any adjacent node has same color, it cannot be used
        if(j!=index && graph[index][j]==1 && color[j]==i){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& graph, vector<int>& color, int n, int m, int index){
    if(index==n){
        return true;
    }
    for(int i=1; i<=m; i++){ // check for all colors
        if(isSafe(graph, color, n, index, i)){
            color[index]=i;
            if(solve(graph, color, n, m, index+1)){ // if rest of graph can be colored, then return true
                return true;
            }
            color[index]=0;
        }
    }
    return false; // if no color can be used
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    int m;
    cin>>m;
    vector<int> color(n, 0);
    if(solve(graph, color, n, m, 0)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}