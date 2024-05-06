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

Node* prev(Node* root, stack<Node*>& lower){
    // find smallest element in remaining BST
    while(root->left){
        lower.push(root);
        root=root->left;
    }
    return root;
}

Node* next(Node* root, stack<Node*>& greater){
    // find largest element in remaining BST
    while(root->right){
        greater.push(root);
        root=root->right;
    }
    return root;
}

bool twoSum(Node* root, int val){
    stack<Node*> lower; // contains lower elements than root
    stack<Node*> greater; // contains greater elements than root
    Node* low=prev(root, lower); // smallest element in BST
    Node* high=next(root, greater); // greatest element in BST
    while(low->data<high->data){
        int sum=low->data+high->data;
        if(sum==val){ // if value found, return true
            return true;
        }
        else if(sum>val){
            if(high->left){ // find greatest node in left subtree of current high
                high=next(high->left, greater);
            }
            else if(!greater.empty()){ // else move to previous largest element
                high=greater.top();
                greater.pop();
            }
            else{ // if no nodes remaining
                return false;
            }
        }
        else if(sum<val){
            if(low->right){ // find smallest node in right subtree of current low
                low=prev(low->right, lower);
            }
            else if(!lower.empty()){ // else move to previous smallest element
                low=lower.top();
                lower.pop();
            }
            else{ // if no nodes remaining
                return false;
            }
        }
    }
    return false;
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
    int val;
    cin>>val;
    if(twoSum(root, val)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}