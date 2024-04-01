#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkIdentical(Node* p, Node* q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
    // values of nodes should be same and their left and right subtrees should be identical respectively
    return p->data==q->data && checkIdentical(p->left, q->left) && checkIdentical(p->right, q->right);
}

int main(){
    int n;
    cin >> n;
    Node *root1 = new Node(n);
    queue<Node *> q;
    q.push(root1);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        int l;
        cin >> l;
        if(l!=-1){
            curr->left = new Node(l);
            q.push(curr->left);
        }
        int r;
        cin >> r;
        if(r!=-1){
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    int m;
    cin>>m;
    Node *root2 = new Node(m);
    q.push(root2);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        int l;
        cin >> l;
        if(l!=-1){
            curr->left = new Node(l);
            q.push(curr->left);
        }
        int r;
        cin >> r;
        if(r!=-1){
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    if(checkIdentical(root1, root2)){
        cout<<"Identical"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    return 0;
}