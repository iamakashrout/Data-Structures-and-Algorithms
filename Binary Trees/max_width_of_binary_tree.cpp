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

// maximum width of any level in a binary tree

int maxWidth(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<pair<Node*, int>> q; // stores node and its horizontal position
    q.push({root, 0});
    while(!q.empty()){
        int n=q.size();
        int currMin=q.front().second; // minimum position at current level
        int left, right;
        for(int i=0; i<n; i++){
            int currIndex=q.front().second-currMin;
            Node* temp=q.front().first;
            q.pop();
            if(i==0){
                left=currIndex; // leftmost position at level
            }
            if(i==n-1){
                right=currIndex; // rightmost position at level
            }
            if(temp->left){
                q.push({temp->left, 2*currIndex+1});
            }
            if(temp->right){
                q.push({temp->right, 2*currIndex+2});
            }
        }
        ans=max(ans, right-left+1); // compare width of current level with max width
    }
    return ans;
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
    int width=maxWidth(root);
    cout<<width<<endl;
    return 0;
}