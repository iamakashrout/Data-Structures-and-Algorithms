#include<bits/stdc++.h>
using namespace std;

// array a represents lengths of words, k is maximum characters allowed on line
// arrange words in lines with minimum cost
// cost is defined as characters unused at the end of each line squared except the last line

int solve(vector<int>& a, int k, vector<int>& dp, int index){
    if(dp[index]!=-1){
        return dp[index];
    }
    int ans=INT_MAX;
    int sum=0;
    for(int i=index; i<a.size(); i++){
        sum+=a[i];
        if(k-sum>=0 && i==a.size()-1){ // if last word and last line
            return 0;
        }
        if(k-sum>=0){ // take word, move to next line and solve
            ans=min(ans, (k-sum)*(k-sum)+solve(a, k, dp, i+1));
        }
        sum++; // try adding another word in same line
    }
    dp[index]=ans; // cost value for current word
    return dp[index];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    vector<int> dp(n, -1); // stores minimum cost after taking each word
    int ans=solve(a, k, dp, 0);
    cout<<ans<<endl;
    return 0;
}