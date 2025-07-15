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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        unordered_map<int,int> distMap;
        vector<int> ans;
        //perform level order traversal, bcoz we only need the last encountered node
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
            
            //update each time a node is encountered for each sol
            distMap[dist]=frontNode->data;
            //push chikd nodes with updated col values
            if(frontNode->left)
            q.push({dist-1,frontNode->left});
            if(frontNode->right)
            q.push({dist+1,frontNode->right});
        }
        for(int i=mini; i<=maxi; i++)
        {
            ans.push_back(distMap[i]);
        }
        return ans;
    }
};