#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int src,unordered_map<int,bool> &visited,vector<vector<int>>& isConnected)
    {
        visited[src]=true;//mark visited
        //find all the adjacent vertices to the src that are not visited and call dfs
        for(int i=0; i<isConnected[src].size(); i++)
        {
            if(!visited[i] && isConnected[src][i]==1)
            {
                dfs(i,visited,isConnected);
            }
        }
    }
    //adjacency matrix is given
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        unordered_map<int,bool> visited;
        int cnt=0;
        //perform dfs to count number of components
        /*try each node as a starting point of our dfs, is it not visited,then we
        have a component starting point, increase cnt and cass dfs*/
        for(int src=0; src<m; src++)
        {
            if(!visited[src])
            {
                cnt++;
                dfs(src,visited,isConnected);
            }
        }
        return cnt;
    }
};