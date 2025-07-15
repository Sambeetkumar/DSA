#include <bits/stdc++.h>
using namespace std;
/*The idea is to build a topological stack considering 0 as src, so 0 will always be
at the top of the stack*/
class Solution {
    //u-->{v,w}
    unordered_map<int,vector<pair<int,int>>> adjList;
    unordered_map<int,bool> visited;
  public:
  //builds topological stack recursively
    void buildTopo(int src,stack<int> &topo){
        for(auto it:adjList[src]){
            if(!visited[it.first]){
                buildTopo(it.first,topo);
            }
        }
        topo.push(src);
        visited[src]=true;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> dist(V,INT_MAX);
        stack<int> topo;
        buildTopo(0,topo);
        //initial case
        dist[0]=0;
        while(!topo.empty()){
            /*pop a node from topological ordering and try minimising it's nbr's cost*/
            int node = topo.top();
            topo.pop();
            for(auto nbr:adjList[node]){
                //if visiting nbr through node is less expensive then update min cost of reaching nbr 
                if(dist[nbr.first]>dist[node]+nbr.second)
                dist[nbr.first]=dist[node]+nbr.second;
            }
        }
        //mark all the INT_MAX with -1, as they can never be visited from 0
        for(int i=0; i<V; i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
