#include <bits/stdc++.h>
using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    void updateMap(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* root)
    {
        if(root==NULL) return;
        if(root->left)
        {
            mp[root->left]=root;
            updateMap(mp,root->left);
        }
        if(root->right)
        {
            mp[root->right]=root;
            updateMap(mp,root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        //map to hash node with its root 
        unordered_map<TreeNode*,TreeNode*> rootOf;
        //set of visited nodes
        unordered_set<TreeNode*> visited;
        updateMap(rootOf,root);//update the map
        int dist=0;
        queue<TreeNode*> q;
        //starting from target node we will move in all possible direction
        q.push(target);
        visited.insert(target);
        while(!q.empty() && dist<k)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();

                if(rootOf.find(frontNode)!=rootOf.end() && visited.find(rootOf[frontNode])==visited.end())
                {
                    q.push(rootOf[frontNode]);
                    visited.insert(rootOf[frontNode]);
                }
                if(frontNode->left && visited.find(frontNode->left)==visited.end())
                {
                    q.push(frontNode->left);
                    visited.insert(frontNode->left);
                }
                if(frontNode->right && visited.find(frontNode->right)==visited.end())
                {
                    q.push(frontNode->right);
                    visited.insert(frontNode->right);
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};