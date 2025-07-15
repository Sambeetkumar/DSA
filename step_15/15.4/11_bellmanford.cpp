#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        /*we need to perform Relaxation step atmost V-1 times to get the final
        diatnce array, here we are running it one more time to detect neg cycle*/
        for(int i=1; i<=V; i++){
            bool isChange = false;
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    //check for negative cycle
                    //if any dist gets updated even after V-1 relaxation steps, then there is a neg cycle
                    if(i==V) return {-1};
                    isChange = true;
                    dist[v]=dist[u]+w;
                }
            }
            //if at any relaxation step all the distances remains same, then no need perform further
            if(!isChange) break;
        }
        return dist;
    }
};
