#include<bits/stdc++.h>
using namespace std;

// finding kth permutation having digits from 1 to n
string kthPerm(int n, int k){
    int permutations=1;
    vector<int> nums;
    for(int i=1; i<n; i++){
        permutations*=i; // number of permuations after fixing first character
        nums.push_back(i);
    }
    nums.push_back(n);
    k--; // to convert to 0 based indexing
    string ans="";
    while(true){
        ans+=to_string(nums[k/permutations]); // find current number
        nums.erase(nums.begin()+k/permutations); // remove from remaining set of numbers
        if(nums.size()==0){
            break;
        }
        k=k%permutations; // order of remaining permutation
        permutations/=nums.size(); // update number of possible permutations for next index
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    string ans=kthPerm(n, k);
    cout<<ans<<endl;
    return 0;
}