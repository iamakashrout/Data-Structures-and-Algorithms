#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n=s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // dp[i][j] represents if substring starting at i and ending at j is palindrome or not
    int start=0;
    int end=0;
    int ans=1;
    // every individual character is palindrome
    for(int i=0; i<n; i++){
        dp[i][i]=true;
    }
    // if two consecutive characters are same
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            if(ans<2){
                ans=2;
                start=i;
                end=i+1;
            }
        }
    }
    for(int len=3; len<=n; len++){
        // for every length, substring(i, j) is palindrome if s[i]=s[j] andd substring(i+1, j-1) is palindrome
        for(int i=0; i<=n-len; i++){
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==true){
                dp[i][j]=true;
                if(ans<len){
                    ans=len;
                    start=i;
                    end=j;
                }
            }
        }
    }
    string result=s.substr(start, ans); // answer string
    return result;
}

int main(){
    string s;
    cin>>s;
    string ans=longestPalindrome(s);
    cout<<ans<<endl;
    return 0;
}