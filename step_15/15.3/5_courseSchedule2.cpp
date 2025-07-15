#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void topoUsingBfs(int course,unordered_map<int,vector<int>> &adjList,vector<int> &ans, unordered_map<int,int> &inDeg)
    {
        //initially push all the independent vertices to queue - indegree 0
        queue<int> q;
        for(int i=0; i<course; i++) {
            if(inDeg[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            //decrease the indegree of all nbrs of popped node,if any node becomes independent
            //push it to queue
            for(auto nbr:adjList[node]){
                inDeg[nbr]--;
                if(inDeg[nbr]==0) {
                    q.push(nbr);
                }
            }
            //as the popped node is independent we can add it to topologial ordering
            ans.push_back(node);
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        unordered_map<int,int> inDeg;
        //create adjList as well as update indegree of verctices
        for(auto it:prerequisites)
        {
            adjList[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }
        vector<int> ans;//to store topological sort
        topoUsingBfs(numCourses,adjList,ans,inDeg);
        //if topological ordering contains all nodes then there is no cycle
        //i.e. we can complete all the courses otherwise we can't
        return ans.size()==numCourses?ans:vector<int>();
    }
};