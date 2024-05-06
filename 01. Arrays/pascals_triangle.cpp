#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        v[i].resize(i+1);
        v[i][0]=1;
        v[i][i]=1;
        for(int j=1; j<i; j++){
            v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}