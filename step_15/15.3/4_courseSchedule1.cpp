#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,bool> visiting;
    unordered_map<int,bool> visited;
    unordered_map<int,vector<int>> adjList;
public:
    bool isCycle(int src)
    {
        //mark the src as visiting as exploring is not completed
        visiting[src]=true;
        bool ans = false;
        for(auto it:adjList[src])
        {
        //if we try to visit a node that is in the current path then cycle is there
            if(visiting[it]) return true;
            if(!visited[it]){
              ans = ans || isCycle(it);//if any nbr detects a cycle return true
              if(ans) {
                return true;
              }
            }
        }
        //completely explored src
        visiting[src]=false;
        visited[src]=true;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*if the graph contains a cycle we can't complete all the courses or
        we can say we can't find the topological ordering*/
        //creating adj list from given edges
        for(auto it:prerequisites)
        {
            adjList[it[1]].push_back(it[0]);
        }
        bool flag = false;
        for(int i=0; i<numCourses; i++)
        {
            /*trying to find cycle in all components, if any component contains a
            cycle, then return false as we can't find topological ordering*/
            if(!visited[i]) {
              flag = flag || isCycle(i);
              if(flag) {
                return false;
              }
            }
        }
        return true;
    }
};