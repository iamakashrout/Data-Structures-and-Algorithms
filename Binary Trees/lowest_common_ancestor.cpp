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

Node* LCA(Node* root, int p, int q){
    // if root has value equal to any one of the required nodes, it is the LCA, or NULL if not found
    if(root==NULL || root->data==p || root->data==q){
        return root;
    }
    root->left=LCA(root->left, p, q); // find LCA from left subtree
    root->right=LCA(root->right, p, q); // find LCA from right subtree
    if(root->right==NULL){ // if right subtree does not have any one value
        return root->left;
    }
    if(root->left==NULL){ // if left subtree does not have any one value
        return root->right;
    }
    return root; // if both left and right subtrees have one value each
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