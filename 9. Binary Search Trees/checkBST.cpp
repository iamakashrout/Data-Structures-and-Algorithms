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

bool check(Node* root, int small, int large){
    if(root==NULL){
        return true;
    }
    return root->data > small && root->data < large && check(root->left, small, root->data) && check(root->right, root->data, large);
}

bool checkBST(Node* root){
    return check(root, INT_MIN, INT_MAX);
}

int main(){
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    cout << checkBST(root) << endl;
    Node *root2 = new Node(5);
    root2->left = new Node(7);
    root2->right = new Node(3);
    cout << checkBST(root2) << endl;
    return 0;
}