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

// build BST from preorder and postorder traversals

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

Node* buildFromPreorder(vector<int>& preorder, int lower, int upper, int& index){
    if(index>=preorder.size()){
        return NULL;
    }
    if(preorder[index]<lower || preorder[index]>upper){ // limits for node value
        return NULL;
    }
    Node* root=new Node(preorder[index]); // first index at root
    index++;
    // left subtree should have values less than root node
    // right subtree should have values more than root node
    root->left=buildFromPreorder(preorder, lower, root->data, index); // then build left subtree
    root->right=buildFromPreorder(preorder, root->data, upper, index); // followed by right subtree
    return root;
}

Node* preorderToBST(vector<int>& preorder){
    int index=0;
    return buildFromPreorder(preorder, INT_MIN, INT_MAX, index);
}

Node* buildFromPostorder(vector<int>& postorder, int lower, int upper, int& index){
    if(index<0){
        return NULL;
    }
    if(postorder[index]<lower || postorder[index]>upper){
        return NULL;
    }
    // start from behind for post order
    Node* root=new Node(postorder[index]); // last index as root
    index--;
    // then build right subtree followed by left subtree
    root->right=buildFromPostorder(postorder, root->data, upper, index);
    root->left=buildFromPostorder(postorder, lower, root->data, index);
    return root;
}

Node* postorderToBST(vector<int>& postorder){
    int index=postorder.size()-1;
    return buildFromPostorder(postorder, INT_MIN, INT_MAX, index);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int op;
    cin>>op;
    if(op==1){
        Node* bst=preorderToBST(arr);
        printTree(bst);
    }
    else if(op==2){
        Node* bst=postorderToBST(arr);
        printTree(bst);
    }
    return 0;
}