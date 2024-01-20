#include <bits/stdc++.h>
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

Node *build(vector<int> &post, vector<int> &in, int postS, int postE, int inS, int inE)
{
    if (postS > postE)
    {
        return NULL;
    }
    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPostS = postS;
    int leftPostE = leftPostS + leftInE - leftInS;
    int rightPostS = leftPostE + 1;
    int rightPostE = postE-1;
    int rightInS = rootIndex + 1;
    int rightInE = inE;
    Node *root = new Node(rootData);
    root->left = build(post, in, leftPostS, leftPostE, leftInS, leftInE);
    root->right = build(post, in, rightPostS, rightPostE, rightInS, rightInE);
    return root;
}

Node *buildTree(vector<int> &post, vector<int> &in)
{
    return build(post, in, 0, post.size() - 1, 0, in.size() - 1);
}

int main()
{
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    Node *tree = buildTree(post, in);
    levelOrder(tree);
    return 0;
}