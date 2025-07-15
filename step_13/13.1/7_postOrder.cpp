#include <bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* lastVisited = NULL;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        if(root==NULL)
        return ans;
        while(!st.empty() || curr != NULL)
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* peekNode = st.top();
                if(peekNode->right && peekNode->right != lastVisited)
                {
                    curr = peekNode->right;
                }
                else
                {
                    ans.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }
        return ans;
    }
};