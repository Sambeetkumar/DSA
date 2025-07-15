#include <bits/stdc++.h>
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
    int findLeftHeight(TreeNode* root)
    {
        int cnt=0;
        while(root)
        {
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int findRightHeight(TreeNode* root)
    {
        int cnt=0;
        while(root)
        {
            cnt++;
            root=root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        //at each node check for perfect binary in order to reduce complexity
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh==rh)//full complete binary tree
        return (1<<lh)-1;

        int lans = countNodes(root->left);
        int rans = countNodes(root->right);

        return 1+lans+rans;
    }
};