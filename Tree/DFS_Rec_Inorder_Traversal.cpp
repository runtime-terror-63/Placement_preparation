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
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
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
  cout << "Enter data for inserting in the left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter data for inserting in the right of " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

void inorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

int32_t main()
{
  Node *root = NULL;
  root = buildTree(root);
  inorderTraversal(root);
}
