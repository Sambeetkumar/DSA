#include<bits/stdc++.h>
using namespace std;
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  //push all the left view nodes
    void leftBoundary(Node* root,vector<int> &ans){
        if(root->left==NULL && root->right==NULL){
            return;
        }
        ans.push_back(root->data);
        //going left is first priority
        if(root->left){
            leftBoundary(root->left,ans);
        }
        else{
            leftBoundary(root->right,ans);
        }
    }
    //push all the leaf nodes
    void leafBoundary(Node* root,vector<int> &ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        if(root->left){
            leafBoundary(root->left,ans);
        }
        if(root->right){
            leafBoundary(root->right,ans);
        }
    }
    //push all the right view nodes
    void rightBoundary(Node* root,vector<int>& ans){
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            rightBoundary(root->right,ans);
        }
        else{
            rightBoundary(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        //edge case - 1
        if(root==NULL) return ans;
        ans.push_back(root->data);
        //edge case - 2
        if(root->left==NULL && root->right==NULL) return ans;
        if(root->left)
        leftBoundary(root->left,ans);
        leafBoundary(root,ans);
        if(root->right)
        rightBoundary(root->right,ans);
        
        return ans;
        
    }
};