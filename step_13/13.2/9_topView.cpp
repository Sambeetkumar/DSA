#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        //col---node - each col will be linked with atmax one node
        unordered_map<int,Node*> distMap;
        vector<int> ans;
        //perform level order traversal, bcoz we only need the first encountered node
        //for each col
        queue<pair<int,Node*>> q;
        q.push({0,root});
        int mini = INT_MAX;
        int maxi = INT_MIN;
        while(!q.empty())
        {
            pair<int,Node*> front = q.front();
            q.pop();
            
            int dist = front.first;
            Node* frontNode = front.second;
            mini = min(mini,dist);
            maxi = max(maxi,dist);
            
            if(distMap.find(dist)==distMap.end())
            {
                distMap[dist]=frontNode;
            }
            if(frontNode->left)
            q.push({dist-1,frontNode->left});
            if(frontNode->right)
            q.push({dist+1,frontNode->right});
        }
        for(int i=mini; i<=maxi; i++)
        {
            ans.push_back(distMap[i]->data);
        }
        return ans;
    }
};
