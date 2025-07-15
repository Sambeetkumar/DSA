#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(int src,unordered_map<int,int> &colored,vector<vector<int>>& graph)
    {
        queue<int> q;
        //push src to queue and color it as 1
        q.push(src);
        colored[src]=1;
        while(!q.empty())
        {
            int node = q.front();
            int color = colored[node];//color of popped node
            q.pop();
            for(auto it:graph[node]) {
                //if adj node is not colored, color it as opposite and push to q
                if(colored[it]==0) {
                    colored[it] = color==1?2:1;
                    q.push(it);
                }
                //if adj node is already colored, compare its color with parent color
                else if(colored[it]==color) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //not colored - 0, two colors are 1 and 2
        unordered_map<int,int> colored;
        bool ans=true;
        for(int i=0; i<graph.size(); i++)
        {
            if(colored[i]==0)//if already colored no need to call function solve
            ans=ans&&(solve(i,colored,graph));
            if(!ans)
            return false;
        }
        return ans;
    }
};