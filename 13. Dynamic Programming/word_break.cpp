#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string word, vector<string>& dictionary, int index){
    int n=word.size();
    if(index==n){
        return true;
    }
    for(int j=index; j<n; j++){
        string rem=word.substr(index, j-index+1); // take word from index to j and check in dictionary
        if(count(dictionary.begin(), dictionary.end(), rem) && wordBreak(word, dictionary, j+1)){ // solve for remaining part
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<string> dictionary(n);
    for(int i=0; i<n; i++){
        cin>>dictionary[i];
    }
    string word;
    cin>>word;
    if(wordBreak(word, dictionary, 0)==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}