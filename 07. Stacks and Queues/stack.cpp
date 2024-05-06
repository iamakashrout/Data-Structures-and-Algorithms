#include<bits/stdc++.h>
using namespace std;

class StackDS{
    public:
    vector<int> data;
    int next;
    int capacity;

    StackDS(){ // constructor
        data = vector<int>(4);
        next = 0;
        capacity = 4;
    }

    int size(){ // returns size of stack
        return next;
    }

    bool isEmpty(){ // checks if stack is empty
        return next == 0;
    }

    void push(int element){ // inserting element into stack
        if(next==capacity){
            vector<int> newData = vector<int>(2 * capacity);
            for (int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            data = newData;
        }
        data[next] = element;
        next++;
    }

    int pop(){ // removing topmost element of stack
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        next--;
        return data[next];
    }

    int top(){ // getting topmost element of stack
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[next - 1];
    }

    void print(){
        if(isEmpty()){
            return;
        }
        int x = top();
        pop();
        print();
        cout << x << " ";
        push(x);
    }
};

int main(){
    StackDS st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x==0){
            int push;
            cin >> push;
            st.push(push);
        }
        else if(x==1){
            st.pop();
        }
        else{
            cout<<st.top()<<endl;
        }
        st.print();
        cout << endl;
    }
    return 0;
}