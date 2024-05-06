#include<bits/stdc++.h>
using namespace std;

// given an array of n elements with numbers from 1 to n where one number is missing and one number is occurring twice
// find the missing and repeating numbers
pair<int, int> solve(vector<int>& a){
    int n=a.size();
    int xor1=0; // xor of all numbers from 1 to n
    for(int i=1; i<=n; i++){
        xor1=(xor1^i);
    }
    int xor2=0; // xor of all numbers in the array
    for(int i=0; i<n; i++){
        xor2=(xor2^a[i]);
    }
    int xorAll=xor1^xor2; // combining the xors cancels all elements occurring once
    // xor of missing and repeating element is left
    int rightMostSetBit=(xorAll&(~(xorAll-1))); // find first position of difference in bits
    int oneBits=0; // numbers with set bit at required position
    int zeroBits=0; // numbers with unset bit at required position
    for(int i=1; i<=n; i++){ // xor with all numbers from 1 to n
        if(i&rightMostSetBit){
            oneBits=(oneBits^i);
        }
        else{
            zeroBits=(zeroBits^i);
        }
    }
    for(int i=0; i<n; i++){ // xor with all numbers of array
        if(a[i]&rightMostSetBit){
            oneBits=(oneBits^a[i]);
        }
        else{
            zeroBits=(zeroBits^a[i]);
        }
    }
    // finally oneBits and zeroBits represent the missing and repeating numbers
    // find count of each in array and return
    int missing, repeating;
    int count=0;
    for(int i=0; i<n; i++){
        if(a[i]==oneBits){
            count++;
        }
    }
    if(count==2){
        missing=zeroBits;
        repeating=oneBits;
    }
    else{
        missing=oneBits;
        repeating=zeroBits;
    }
    return {missing, repeating};
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    pair<int, int> ans=solve(a);
    cout<<"Missing: "<<ans.first<<endl;
    cout<<"Repeating: "<<ans.second<<endl;
    return 0;
}