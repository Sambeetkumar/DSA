#include <bits/stdc++.h>
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
class Solution
{
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pStart, int pEnd, int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || pStart > pEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[pStart]);
        int inRootInd = inMap[preorder[pStart]];
        int leftElCnt = inRootInd - inStart;
        int rightElCnt = inEnd - inRootInd;
        root->left = build(preorder, inorder, pStart + 1, pStart + leftElCnt, inStart, inRootInd - 1, inMap);
        root->right = build(preorder, inorder, pEnd - rightElCnt + 1, pEnd, inRootInd + 1, inEnd, inMap);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inMap;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            inMap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1, inMap);
    }
};