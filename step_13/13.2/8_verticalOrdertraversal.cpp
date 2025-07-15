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
    //col -> {row-->sorted nodes}
    map<int,map<int,multiset<int>>> mp;
public:
    void solve(TreeNode* root,int row,int col){
        if(root==NULL){
            return;
        }
        mp[col][row].insert(root->val);
        solve(root->left,row+1,col-1);
        solve(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> res;
        for(auto col:mp){
            vector<int> ans;
            for(auto row:col.second){
                for(auto el:row.second){
                    ans.push_back(el);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};