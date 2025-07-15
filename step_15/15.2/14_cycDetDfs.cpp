#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,bool> visiting;
    unordered_map<int,bool> visited;
    unordered_map<int,vector<int>> adjList;
public:
    bool isCycleUsingDfs(int src)
    {
        //mark the src as visiting as exploring is not completed
        visiting[src]=true;
        bool ans = false;
        for(auto it:adjList[src])
        {
        //if we try to visit a node that is in the current path then cycle is there
            if(visiting[it]) return true;
            if(!visited[it]){
              ans = ans || isCycleUsingDfs(it);//if any nbr detects a cycle return true
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
    bool canFinish(int V, vector<vector<int>>& edges) {
        //create adjList from edges
        for(auto it:edges)
        {
            adjList[it[0]].push_back(it[1]);
        }
        bool flag = false;
        for(int i=0; i<V; i++)
        {
            /*trying to find cycle in all components, if any component contains a
            cycle, then return true as cycle is present*/
            if(!visited[i]) {
              flag = flag || isCycleUsingDfs(i);
              if(flag) {
                return true;
              }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {3,0}};
    Solution obj;
    cout << obj.canFinish(6, edges);
}