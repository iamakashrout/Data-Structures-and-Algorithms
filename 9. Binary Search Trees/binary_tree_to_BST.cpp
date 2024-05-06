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

void printTree(Node* root){ // print tree
    if(root==NULL){
        return;
    }
    cout << root->data <<": ";
    if(root->left!=NULL){
        cout << "L:" << root->left->data << " ";
    }
    if(root->right!=NULL){
        cout << "R:" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void inOrderArray(Node* root, vector<int>& v){
    if(root==NULL){
        return;
    }
    inOrderArray(root->left, v);
    v.push_back(root->data);
    inOrderArray(root->right, v);
}

void inOrderBST(Node* root, vector<int>& v, int& index){
    if(root==NULL){
        return;
    }
    inOrderBST(root->left, v, index);
    root->data=v[index]; // replace nodes with node which will occur in BST
    index++;
    inOrderBST(root->right, v, index);
}

Node* buildBST(Node* root){
    vector<int> v;
    inOrderArray(root, v); // find inorder traversal of binary tree
    sort(v.begin(), v.end()); // sort the inorder traversal
    int index=0;
    inOrderBST(root, v, index); // replace nodes according to sorted inorder to form BST
    return root;
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
    Node* bst=buildBST(root);
    printTree(bst);
    return 0;
}