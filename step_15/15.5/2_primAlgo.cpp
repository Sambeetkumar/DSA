#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V,0);
        int sum =0;
        //{node----weight}
        pq.push({0,0});
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            int wt = front.first;
            //if node is already visited
            if(visited[node]){
                continue;
            }
            //else mark it visited and add the weight to sum
            visited[node]=1;
            sum+=wt;
            //visit adj nodes
            for(auto it:adj[node]){
                int nbrNode = it[0];
                int nbrWeight = it[1];
                if(!visited[nbrNode]){
                    pq.push({nbrWeight,nbrNode});
                }
            }
        }
        return sum;
    }
};