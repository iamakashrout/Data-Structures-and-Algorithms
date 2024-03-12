#include<bits/stdc++.h>
using namespace std;

class StackUsingQueue{
    public:
    queue<int> q;
    StackUsingQueue(){

    }

    void push(int x){
        q.push(x);
        for(int i=0; i<q.size()-1; i++){ // add element to front of q, arrange remaining elements after it
            int y=q.front();
            q.pop();
            q.push(y);
        }
    }

    int pop(){
        int x=q.front();
        q.pop();
        return x;
    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){
    StackUsingQueue st;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            st.push(x);
        }
        else if(op==2){
            st.pop();
        }
        else if(op==3){
            cout<<st.top()<<endl;
        }
        else if(op==4){
            cout<<st.empty()<<endl;
        }
        StackUsingQueue temp=st;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
    return 0;
}