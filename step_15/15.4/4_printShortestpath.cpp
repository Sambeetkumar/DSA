#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        unordered_map<int,int> parent;
        vector<int> dist(n+1,INT_MAX);
        set<pair<int,int>> st;
        dist[1]=0;
        parent[1]=-1;
        st.insert({0,1});
        while(!st.empty()){
            auto front = *(st.begin());
            st.erase(st.begin());
            int node = front.second;
            int nodeDist = front.first;
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                if(nodeDist+nbrDist<dist[nbrNode]){
                    auto it = st.find({dist[nbrNode],nbrNode});
                    if(it!=st.end()){
                        st.erase(it);
                    }
                    dist[nbrNode]=nodeDist+nbrDist;
                    st.insert({dist[nbrNode],nbrNode});
                    parent[nbrNode]=node;
                }
            }
        }
        vector<int> ans;
        int targetNode = n;
        while(parent.find(targetNode)!=parent.end()){
            ans.push_back(targetNode);
            targetNode = parent[targetNode];
        }
        if(targetNode==-1){
            ans.push_back(dist[n]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else{
            return {-1};
        }
    }
};