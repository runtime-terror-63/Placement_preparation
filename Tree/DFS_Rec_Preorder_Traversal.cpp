#include <bits/stdc++.h>
using namespace std;

#define int long long

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->left = nullptr;
    this->right = nullptr;
    this->data = data;
  }
};

Node *buildTree(Node *root)
{
  cout << "Enter the data" << endl;
  int data;
  cin >> data;
  root = new Node(data);
  if (data == -1)
    return NULL;
  cout << "Enter the data for inserting in the left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter the data for inserting in the right of " << data << endl;
  root->right = buildTree(root->right);
  return root;
}

void preorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

int32_t main()
{
  Node *root = buildTree(root);
  preorderTraversal(root);
}