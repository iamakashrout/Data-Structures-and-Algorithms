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

Node* solve(Node* root, int& k, int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){ // required node
        return root;
    }
    Node* left=solve(root->left, k, x);
    Node* right=solve(root->right, k, x);
    // if required node is found on left subtree
    if(left!=NULL && right==NULL){
        k--;
        if(k<=0){ // when kth ancestor is reached, set k to inifinity and return this node
            k=INT_MAX;
            return root;
        }
        // this node will be returned for all above nodes
        return left; // while kth ancestor is not reached return the original node
    }
    // same in case required node is found on right subtree
    if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }
    return NULL; // if required node not found
}

int kthAncestor(Node* root, int k, int x){
    Node* ans=solve(root, k, x);
    if(ans==NULL || ans->data==x){ // no kth ancestor found
        return -1;
    }
    return ans->data;
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
    int k;
    cin>>k;
    int ans=kthAncestor(root, k, x);
    cout<<ans<<endl;
    return 0;
}