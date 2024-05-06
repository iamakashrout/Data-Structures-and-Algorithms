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

vector<int> solve(Node* root, int& ans){
    if(root==NULL){
        return {INT_MAX, INT_MIN, 0};
    }
    vector<int> left=solve(root->left, ans);
    vector<int> right=solve(root->right, ans);
    // if left or right subtree are not BST or value of root does not lie in range, it is not BST
    if(left.empty() || right.empty() || root->data<=left[1] || root->data>=right[0]){
        return {};
    }
    int curr=left[2]+right[2]+root->data; // total sum of subtree
    ans=max(ans, curr); // update ans
    return {min(left[0], root->data), max(right[1], root->data), curr}; // pass to parent
}

int maxSumBST(Node* root){
    int ans=0;
    solve(root, ans);
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
    int ans=maxSumBST(root);
    cout<<ans<<endl;
    return 0;
}