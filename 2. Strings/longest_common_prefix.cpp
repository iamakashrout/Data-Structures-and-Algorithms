#include<bits/stdc++.h>
using namespace std;

string lcp(vector<string>& v){
    sort(v.begin(), v.end());
    string first=v[0];
    string last=v[v.size()-1];
    string ans="";
    for(int i=0; i<min(first.size(), last.size()); i++){
        if(first[i]!=last[i]){
            return ans;
        }
        ans.push_back(first[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    string ans=lcp(v);
    cout<<ans<<endl;
    return 0;
}