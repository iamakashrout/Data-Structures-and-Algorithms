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

void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
    levelOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}