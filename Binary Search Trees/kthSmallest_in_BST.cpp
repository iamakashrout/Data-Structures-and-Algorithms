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

int kthSmallest(Node* root, int k){
    stack<Node*> st;
    Node* temp=root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left; // go to leftmost node adding all nodes on the way to stack
        }
        temp=st.top();
        st.pop();
        k--; // decrement k and pop smallest node
        if(k==0){ // if k becomes 0, the kth smallest node has been found
            return temp->data;
        }
        temp=temp->right; // else move to the right of the smallest node and check
    }
    return -1;
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
    int k;
    cin>>k;
    int ans=kthSmallest(root, k);
    cout<<ans<<endl;
    return 0;
}