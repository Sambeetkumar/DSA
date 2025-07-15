#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> dist(V,-1);
        set<pair<int,int>> st;
        st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());
            int topNode = top.second;
            int topNodeDist = top.first;
            for(auto nbr:adjList[topNode]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                if(dist[nbrNode]==-1 || topNodeDist+nbrDist<dist[nbrNode]){
                    //find the nbr's entry in set and delete(if present) and insert new entry
                    auto oldEntry = st.find({dist[nbrNode],nbrNode});
                    if(oldEntry != st.end()){
                        st.erase(oldEntry);
                    }
                    //update nbr's dist
                    dist[nbrNode]=topNodeDist+nbrDist;
                    //insert it into set
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        return dist;
    }
};