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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        //try labelling the nodes like left = 2*root, right = 2*root+1
        q.push({root,1});
        int maxWidth=0;
        while(!q.empty()){
            int s = q.size();
            long long start=q.front().second;
            long long last=0;
            for(int i=0; i<s; i++){
                pair<TreeNode*,long long> f = q.front();
                q.pop();
                TreeNode* currNode=f.first;
                long long currLabel=f.second;
                if(i==s-1){
                    last=currLabel;
                }
                if(currNode->left){
                    q.push({currNode->left,2*currLabel});
                }
                if(currNode->right){
                    q.push({currNode->right,2*currLabel+1});
                }
            }
            //calc width levelwise and update maxWidth
            int width = last-start+1;
            maxWidth=max(maxWidth,width);
        }
        return maxWidth;
    }
};