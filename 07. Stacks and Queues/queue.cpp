#include<bits/stdc++.h>
using namespace std;

class QueueDS{
    public:
    vector<int> data;
    int next; // next index where element can be inserted
    int first; // first element of queue
    int length;
    int capacity;

    QueueDS(){
        data = vector<int>(4);
        next = 0;
        first = -1;
        length = 0;
        capacity = 4;
    }

    int size(){ // size of queue
        return length;
    }

    bool isEmpty(){ // checks if queue is empty
        return length == 0;
    }

    void push(int element){ // insert element to end of queue
        if(length==capacity){
            vector<int> newData = vector<int>(2 * capacity);
            int j = 0;
            for (int i = first; i < capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < first; i++){
                newData[j] = data[i];
                j++;
            }
            data = newData;
            first = 0;
            next = capacity;
            capacity *= 2;
        }
        data[next] = element;
        next = (next + 1) % capacity;
        if(first==-1){
            first = 0;
        }
        length++;
    }

    int pop(){ // remove first element of queue
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int temp = data[first];
        first = (first + 1) % capacity;
        length--;
        if(length==0){
            first = -1;
            next = 0;
        }
        return temp;
    }

    int front(){ // get first element of queue
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[first];
    }
};

void print(QueueDS q){ // print a queue
    QueueDS temp = q;
    while(!temp.isEmpty()){
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main(){
    QueueDS q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            int push;
            cin >> push;
            q.push(push);
        }
        else if (x == 1)
        {
            q.pop();
        }
        else
        {
            cout << q.front() << endl;
        }
        print(q);
        cout << endl;
    }
    return 0;
}