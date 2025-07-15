#include<bits/stdc++.h>
using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int findDiameter(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        //find the left max left subtree depth and right subtree depth
        int left = findDiameter(root->left,diameter);
        int right = findDiameter(root->right,diameter);
        
        //max diamter will distance between deepest node in left and deepest node in right
        diameter = max(left+right,diameter);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int maxDepth = findDiameter(root,diameter);
        return diameter;
    }
};