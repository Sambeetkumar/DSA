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
    //recursive approach
    void funcPre(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        ans.push_back(root->val);
        funcPre(root->left,ans);
        funcPre(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       funcPre(root,ans);

       return ans; 
    }
    //iterative approach
    vector<int> preIterative(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* topNode = st.top();
            st.pop();
            ans.push_back(topNode->val);
            //push right node first
            if(topNode->right){
                st.push(topNode->right);
            }
            //then push left node
            if(topNode->left){
                st.push(topNode->left);
            }
        }
        return ans;
    }
};