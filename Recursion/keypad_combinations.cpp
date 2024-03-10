#include<bits/stdc++.h>
using namespace std;

void keypadCombinations(vector<vector<char>>& keypad, vector<int>& v, vector<string>& ans, int index, string temp){
    if(index==v.size()){
        ans.push_back(temp);
        return;
    }
    int digit=v[index];
    for(int i=0; i<keypad[digit].size(); i++){ // for all letters represented by each digit, find all results
        keypadCombinations(keypad, v, ans, index+1, temp+keypad[digit][i]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<char>> keypad={{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    vector<string> ans;
    keypadCombinations(keypad, v, ans, 0, "");
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}