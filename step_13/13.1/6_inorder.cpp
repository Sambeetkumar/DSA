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
class Solution {
public:
//recursive approach
    void func(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        return;

        func(root->left,v);
        v.push_back(root->val);
        func(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root,ans);

        return ans;
    }
    //iterative approach
    vector<int> inOrderIterative(TreeNode* root){
        vector<int> ans;
        //edge case
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        //initally go as far left as possible
        TreeNode* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        //now start processing
        while(!st.empty()){
            //pop the top node and add it to ans
            TreeNode* topNode = st.top();
            st.pop();
            ans.push_back(topNode->val);

            //if right child of topNode exist then go as left as possible from the
            //left child of topNode
            if(topNode->right){
                TreeNode* rightNode = topNode->right;
                while(rightNode){
                    st.push(rightNode);
                    rightNode = rightNode->left;
                }
            }
        }
        return ans;
    }
};