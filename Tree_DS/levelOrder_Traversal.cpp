#include<bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
};

Node* newNode(int data){
  Node* node = new Node();
  node->val = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

vector<vector<int>>levelOrderTraversal(Node* root){
  vector<vector<int>>ans;
  if(root==NULL)return ans;
  queue<Node*>que;
  que.push(root);
  while(!que.empty()){
    vector<int>lvl;
    int size = que.size();
    for(int i = 0; i<size;i++){
      Node* vol = que.front();
      que.pop();
      lvl.push_back(vol->val);

      if(vol->left != NULL) que.push(vol->left);
      if(vol->right != NULL) que.push(vol->right);
    }
     ans.push_back(lvl);
  }

  return ans;
}

void printVector(const vector<int>&vec){
  for(int num : vec) cout<<num<<" ";
  //cout<<endl;
}

int main(){
  Node* root =  newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  vector<vector<int>>res = levelOrderTraversal(root);
  for(vector<int>&lvevl : res) printVector(lvevl);
  
}