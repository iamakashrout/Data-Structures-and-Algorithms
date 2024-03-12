#include<bits/stdc++.h>
using namespace std;

priority_queue<int> lesserHalf; // lower half elements
priority_queue<int, vector<int>, greater<int>> greaterHalf; // greater half elements

void add(int num){
    lesserHalf.push(num);
    int x=lesserHalf.top();
    lesserHalf.pop();
    greaterHalf.push(x);
    if(lesserHalf.size()<greaterHalf.size()){
        int y=greaterHalf.top();
        greaterHalf.pop();
        lesserHalf.push(y);
    }
}

double median(){
    if(lesserHalf.size()>greaterHalf.size()){
        return lesserHalf.top();
    }
    return (lesserHalf.top()+greaterHalf.top())/2.0;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int op;
        cin>>op;
        if(op==1){ // add element to data
            int x;
            cin>>x;
            add(x);
        }
        else if(op==2){ // find median of data
            double x=median();
            cout<<median()<<endl;
        }
    }
    return 0;
}