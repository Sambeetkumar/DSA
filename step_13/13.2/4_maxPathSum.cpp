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
    int findmax(TreeNode* root,int &ans)
    {
        if(root==NULL)
        return 0;
        int left = findmax(root->left,ans);
        int right = findmax(root->right,ans);

        ans = max(ans,left+right+root->val);
        //if any of the substree is contributing negative then ignore it
        return max(left,right)+root->val>0 ? max(left,right)+root->val : 0;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findmax(root,ans);

        return ans;
    }
};