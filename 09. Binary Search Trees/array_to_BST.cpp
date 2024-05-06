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

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

Node* build(vector<int>& arr, int start, int end){
    if(end<start){
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = build(arr, start, mid - 1);
    root->right = build(arr, mid + 1, end);
    return root;
}

Node* buildTree(vector<int>& arr){
    return build(arr, 0, arr.size() - 1);
}

int main(){
    vector<int> arr = {3, 5, 8, 11, 16, 21, 26, 30, 33, 36, 40, 45, 52};
    Node *root = buildTree(arr);
    levelOrder(root);
    return 0;
}