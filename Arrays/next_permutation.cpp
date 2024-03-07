#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& perm){
    int n=perm.size();
    int index=-1;
    for(int i=n-2; i>=0; i--){
        if(perm[i]<perm[i+1]){ // find last element which is in not in descending order
        // last sequence at this index for current digit
            index=i;
            break;
        }
    }
    if(index!=-1){
        for(int i=n-1; i>index; i--){
            if(perm[i]>perm[index]){ // find element just greater than it
                swap(perm[i], perm[index]);
                break;
            }
        }
    }
    reverse(perm.begin()+index+1, perm.end()); // remaining part after it (first sequence at index for next digit)
}

int main(){
    int n;
    cin>>n;
    vector<int> perm(n);
    for(int i=0; i<n; i++){
        cin>>perm[i];
    }
    nextPermutation(perm);
    for(int i=0; i<n; i++){
        cout<<perm[i]<<" ";
    }
    cout<<endl;
    return 0;
}