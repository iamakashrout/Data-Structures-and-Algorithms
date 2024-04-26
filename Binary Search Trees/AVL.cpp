#include<bits/stdc++.h>
using namespace std;

// AVL Tree: Self Balancing Binary Search Tree
// after every addition and deletion, difference between heights of left and right subtrees of all nodes is <=1

class Node{ // AVL Node
public:
    int data; // value of data stored
    Node* left; // left child
    Node* right; // right child
    int height; // height of node

    Node(int val){ // constructor for AVL Node
        data=val;
        left=NULL;
        right=NULL;
        height=1;
    }
};

int getHeight(Node* root){ // function get height of node
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int balanceFactor(Node* root){ // difference between heights of left and right subtrees of node
    if(root==NULL){
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}

// left rotate about a node
/*
1              2
 2   becomes  1 3
  3
*/
Node* leftRotate(Node* root){
    Node* x=root->right;
    Node* y=x->left;
    x->left=root;
    root->right=y;
    root->height=1+max(getHeight(root->left), getHeight(root->right)); // updating heights
    x->height=1+max(getHeight(x->left), getHeight(x->right));
    return x;
}

// right rotate about a node
/*
  1            2
 2   becomes  1 3
3
*/
Node* rightRotate(Node* root){
    Node* x=root->left;
    Node* y=x->right;
    x->right=root;
    root->left=y;
    root->height=1+max(getHeight(root->left), getHeight(root->right)); // updating heights
    x->height=1+max(getHeight(x->left), getHeight(x->right));
    return x;
}

// inserting node in AVL
Node* insertNode(Node* root, int val){
    if(root==NULL){
        Node* newNode=new Node(val);
        return newNode;
    }
    if(root->data>val){ // if root is greater than val, insert in left subtree
        root->left=insertNode(root->left, val);
    }
    else if(root->data<val){ // if root is smaller than val, insert in right subtree
        root->right=insertNode(root->right, val);
    }
    else{ // AVL does not allow duplicate values
        return root;
    }
    root->height=1+max(getHeight(root->left), getHeight(root->right)); // updating height of root
    int balance=balanceFactor(root); // difference between left and right subtrees
    if(balance>1){ // if left subtree is larger and causes imbalance
        if(root->left->data>val){ // left left case, right rotate about root
            return rightRotate(root);
        }
        else{
            root->left=leftRotate(root->left); // left right case, first left rotate about root->left
            return rightRotate(root); // then right rotate about root
        }
    }
    else if(balance<-1){ // if right subtree is larger and causes imbalance
        if(root->right->data<val){ // right right case, left rotate about root
            return leftRotate(root);
        }
        else{
            root->right=rightRotate(root->right); // right left case, first right rotate about root->right
            return leftRotate(root); // then left rotate about root
        }
    }
    return root;
}

// deleting node from AVL
Node* deleteNode(Node* root, int val){
    if(root==NULL){ // null AVL
        return root;
    }
    if(root->data>val){ // if root greater than val, delete from left subtree
        root->left=deleteNode(root->left, val);
    }
    else if(root->data<val){ // if root smaller than val, delete from right subtree
        root->right=deleteNode(root->right, val);
    }
    else{ // root equal to val to be removed
        if(root->left==NULL){ // if root->left is NULL, root->right becomes new root
            Node* temp=root->right;
            root=NULL;
            return temp;
        }
        if(root->right==NULL){ // if root->right is NULL, root->left becomes new root;
            Node* temp=root->left;
            root=NULL;
            return temp;
        }
        // if both not null, move to the rightmost node in left subtree
        Node* curr=root->left;
        while(curr->right!=NULL){
            curr=curr->right;
        }
        root->data=curr->data; // replace root with this rightmost node in left subtree
        root->left=deleteNode(root->left, curr->data); // delete this node
        root->height=1+max(getHeight(root->left), getHeight(root->right)); // update height of root
        // check for balanced condition
        int balance=balanceFactor(root);
        if(balance>1){
            if(balanceFactor(root->left)>=0){
                return rightRotate(root);
            }
            else{
                root->left=leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if(balance<-1){
            if(balanceFactor(root->right)<=0){
                return leftRotate(root);
            }
            else{
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
        }
    }
    return root;
}

void printAVL(Node* root){ // print AVL data structure, level order traversal
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
        cout<<curr->data<<" ";
    }
    cout<<endl;
}

int main(){
    int first; // value of first node
    cin>>first;
    Node* root=new Node(first);
    int ops; // no. of operations
    cin>>ops;
    for(int i=0; i<ops; i++){
        int op;
        cin>>op;
        if(op==1){ // for adding node
            int val;
            cin>>val;
            root=insertNode(root, val);
            printAVL(root);
        }
        else if(op==2){ // for deleting node
            int val;
            cin>>val;
            root=deleteNode(root, val);
            printAVL(root);
        }
    }
    return 0;
}