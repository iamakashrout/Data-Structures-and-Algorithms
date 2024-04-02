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

int kthLargest(Node* root, int k){
    stack<Node*> st;
    Node* temp=root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->right; // go to rightmost node adding all nodes on the way to stack
        }
        temp=st.top();
        st.pop();
        k--; // decrement k and pop largest node
        if(k==0){ // if k becomes 0, the kth largest element has been found
            return temp->data;
        }
        temp=temp->left; // else move to the left of the largest node and check
    }
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
    int ans=kthLargest(root, k);
    cout<<ans<<endl;
    return 0;
}