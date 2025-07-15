#include <bits/stdc++.h>
using namespace std;
//recursive approach
class Solution1 {
    unordered_set<int> cycleNodes;
    unordered_map<int,bool> visiting;
    unordered_map<int,bool> visited;
public:
    bool isCycle(int src,vector<vector<int>>& graph) {
        visiting[src]=true;
        bool ans = false;
        for(auto it:graph[src]) {
            /*if we are trying to visit a node that is either in current path or is already
            a cycle node then atleast one path from src will lead to a cycle */
            if(visiting[it] || cycleNodes.find(it)!=cycleNodes.end()) {
                ans = true;
                break;
            }
            else {
                if(!visited[it]) {
                    //if any of the nbr leads to cycle then src will also lead to cycle
                    ans = ans||isCycle(it,graph);
                    if(ans)
                    break;
                }
            }
        }
        //if ans is true mark src as cyclenode
        if(ans) {
            cycleNodes.insert(src);
        }
        //exploring of src is complete
        visiting[src] = false;
        visited[src] = true;
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        for(int i=0; i<graph.size(); i++)
        {
            if(!visited[i])
            isCycle(i,graph);
        }
        vector<int> ans;
        //push all the non-cycle nodes to answer
        for(int i=0; i<graph.size(); i++) {
            if(cycleNodes.find(i)==cycleNodes.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//solution topologocal sort

/*The idea is to reverse all the edges, so that the terminal nodes becomes independent nodes
(indegree 0) and do a topological ordering, all the non-safe nodes will never be included in topological ordering
as they are part of cycle*/
class Solution2 {
    unordered_map<int,vector<int>> revAdjList;
    unordered_map<int,int> inDeg;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i=0; i<graph.size(); i++) {
            for(auto j:graph[i]) {
                revAdjList[j].push_back(i);
                inDeg[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<graph.size(); i++) {
            if(inDeg[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it:revAdjList[node]) {
                inDeg[it]--;
                if(inDeg[it]==0) {
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        //sort the topological ordering before returning
        sort(ans.begin(),ans.end());
        return ans;
    }
};