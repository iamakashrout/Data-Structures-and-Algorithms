#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root, int x, int& pre, int& suc){
    if(root==NULL){
        return;
    }
    if(root->data==x){ // root has value equal to x, search left for predecessor, search right for successor
        solve(root->left, x, pre, suc);
        solve(root->right, x, pre, suc);
    }
    else if(root->data>x){
        // if root greater than x, set successor as root and search for both on left
        suc=root->data;
        solve(root->left, x, pre, suc);
    }
    else if(root->data<x){
        // if root less than x, set predecessor as root and search for both on right
        pre=root->data;
        solve(root->right, x, pre, suc);
    }
}

int main(){
    int n;
    cin >> n;
    Node *root = new Node(n);
    queue<Node *> q;
    q.push(root);
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
    int x;
    cin>>x;
    int pre=-1, suc=-1;
    solve(root, x, pre, suc);
    cout<<"Predecessor: "<<pre<<endl;
    cout<<"Successor: "<<suc<<endl;
    return 0;
}