#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>& q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

void print(queue<int>& q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main(){
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    print(q);
    cout << endl;
    reverse(q);
    print(q);
    return 0;
}