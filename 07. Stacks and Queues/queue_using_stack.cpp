#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    public:
    stack<int> st;
    QueueUsingStack(){

    }

    void push(int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int y=st.top();
        st.pop();
        push(x); // recursively send x to the bottom of stack add remaining elements after it
        st.push(y);
        return;
    }

    int pop(){
        int x=st.top();
        st.pop();
        return x;
    }

    int front(){
        return st.top();
    }

    bool empty(){
        return st.empty();
    }
};

int main(){
    QueueUsingStack q;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(op==2){
            q.pop();
        }
        else if(op==3){
            cout<<q.front()<<endl;
        }
        else if(op==4){
            cout<<q.empty()<<endl;
        }
        QueueUsingStack temp=q;
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
    return 0;
}