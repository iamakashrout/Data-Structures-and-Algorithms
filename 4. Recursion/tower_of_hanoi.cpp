#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary); // move first n-1 discs to aux rod
    cout<<source<<" "<<destination<<endl; // move last rod to destination
    towerOfHanoi(n-1, auxiliary, source, destination); // move first n-1 rods to destination from aux
}

int main(){
    int n;
    cin>>n;
    char source='A';
    char auxiliary='B';
    char destination='C';
    towerOfHanoi(n, source, auxiliary, destination);
    return 0;
}