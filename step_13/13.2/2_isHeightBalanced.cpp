#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int func(TreeNode* root,bool &flag)
    {
        if(root==nullptr)
        return 0;
        int left = 1+func(root->left,flag);
        int right = 1+func(root->right,flag);

        // if at any node height becomes unbalanced mark the flag as false;
        if(abs(left-right)>1)
        flag = false;

        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        func(root,ans);
        return ans;
    }
};