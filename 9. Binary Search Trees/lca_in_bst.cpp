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

Node* LCA(Node* root, int p, int q){
    if(root->data>p && root->data>q){ // if root greater than both values, check left subtree
        return LCA(root->left, p, q);
    }
    if(root->data<p && root->data<q){ // if root less than both values, check right subtree
        return LCA(root->right, p, q);
    }
    return root; // else root is the LCA
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
    int a;
    cin>>a;
    int b;
    cin>>b;
    Node* lca=LCA(root, a, b);
    if(lca==NULL){
        cout<<-1<<endl;
    }
    else{
        cout<<lca->data<<endl;
    }
    return 0;
}