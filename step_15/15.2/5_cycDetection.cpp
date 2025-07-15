#include <bits/stdc++.h>
using namespace std;
class Solution {
  unordered_map<int,vector<int>> adjList;
  public:
    bool usingBfs(int src,unordered_map<int,bool> &visited)
    {
        unordered_map<int,int> parent;//to keep stack of parent
        queue<int> q;
        //start from source,put it into queue,mark visited and mark its parent as -1
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            //put all its not visited nbrs into queue
            for(int it:adjList[front])
            {
                if(!visited[it])
                {
                  visited[it]=true;
                  parent[it]=front;
                  q.push(it);
                }
                //if a nbr is already visited and have some other node as parent, then it is a cycle
                else if(parent[front]!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool usingDfs(int src,unordered_map<int,bool> &visited,unordered_map<int,int> &p)
    {
        visited[src]=true;
        bool ans=false;
        for(int it:adjList[src])
        {
            if(!visited[it])
            {
                p[it]=src;
                ans=usingDfs(it,visited,p);
                if(ans)
                return true;
            }
            else if(p[src]!=it)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        for(int i=0; i<edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,int> dfsParent;
        for(int i=0; i<V; i++)
        {
            bool ans=false;
            if(!visited[i])
            {
                dfsParent[i]=-1;
                ans = usingDfs(i,visited,dfsParent);
                if(ans)
                {
                  return true;
                }
            }
        }
        return false;
    }
};