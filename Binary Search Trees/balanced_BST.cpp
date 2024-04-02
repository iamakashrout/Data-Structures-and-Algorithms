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

// create balanced BST from normal BST

void inOrder(Node* root, vector<int>& v){
    if(root==NULL){
        return;
    }
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

Node* buildBalancedBST(vector<int>& v, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(v[mid]); // set middle element as root
    root->left=buildBalancedBST(v, start, mid-1); // smaller elements on left subtree
    root->right=buildBalancedBST(v, mid+1, end); // greater elements on right subtree
    return root;
}

Node* balancedBST(Node* root){
    vector<int> v;
    inOrder(root, v); // create inorder traversal
    return buildBalancedBST(v, 0, v.size()-1); // build balanced BST
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
    Node* balBST=balancedBST(root);
    printTree(balBST);
    return 0;
}