#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        /*initially mark all -1 as the nodes that can't be reached from src will hold
        final value as -1*/
        vector<int> ans(n,-1);
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(src);//start bfs from src
        //maintain initial state
        visited[src]=true;
        ans[src]=0;
        int cnt=1;//holds level value
        while(!q.empty())
        {
            //update the distances level wise
            int s=q.size();
            for(int i=0; i<s; i++)
            {
                int front = q.front();
                q.pop();
                for(int it:adj[front])
                {
                    if(!visited[it])
                    {
                        visited[it]=true;
                        q.push(it);
                        ans[it]=cnt;
                    }
                }
            }
            cnt++;
        }
        return ans;
    }
};