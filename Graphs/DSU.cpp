#include<bits/stdc++.h>
using namespace std;

// Disjoint Set Union data structure

class DisjointSet{
    public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0); // rank of each component
        parent.resize(n+1); // parent node of each component
        size.resize(n+1, 1); // size of each component
        for(int i=1; i<=n; i++){
            parent[i]=i;
        }
    }

    int findParent(int x){ // find parent node of the component
        if(parent[x]==x){
            return x;
        }
        parent[x]=findParent(parent[x]);
        return parent[x];
    }

    void unionByRank(int x, int y){ // update the parent of lower rank node with that of higher rank node
        int parentX=findParent(x);
        int parentY=findParent(y);
        if(parentX==parentY){
            return;
        }
        if(rank[parentX]<rank[parentY]){
            parent[parentX]=parentY;
        }
        else if(rank[parentX]>rank[parentY]){
            parent[parentY]=parentX;
        }
        else{
            parent[parentX]=parentY;
            rank[parentY]++;
        }
    }

    void unionBySize(int x, int y){ // update the parent of smaller component with that of larger component
        int parentX=findParent(x);
        int parentY=findParent(y);
        if(parentX==parentY){
            return;
        }
        if(size[parentX]<size[parentY]){
            parent[parentX]=parentY;
            size[parentY]+=size[parentX];
        }
        else{
            parent[parentY]=parentX;
            size[parentX]+=size[parentY];
        }
    }
};

int main(){
    int n;
    cin>>n;
    DisjointSet dsu(n);
    int ops;
    cin>>ops;
    for(int i=0; i<ops; i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            cout<<dsu.findParent(x)<<endl;
        }
        else if(op==2){
            int x, y;
            cin>>x>>y;
            dsu.unionBySize(x, y);
        }
        else if(op==3){
            int x, y;
            cin>>x>>y;
            dsu.unionByRank(x, y);
        }
    }
    return 0;
}