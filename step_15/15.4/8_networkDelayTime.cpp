#include <bits/stdc++.h>
using namespace std;
//solution using Dijkstra's Algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //built adjMat
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0; i<times.size(); i++)
        {
            adjList[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        //dist
        vector<int> dist(n,INT_MAX);
        //dist-node
        set<pair<int,int>> st;
        //maintain intial state
        dist[k-1]=0;
        st.insert({0,k-1});
        while(!st.empty()){
            auto front = *(st.begin());
            st.erase(st.begin());
            int node = front.second;
            int nodeDist = front.first;
            //pop the front node and try visiting its nbrs
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                //if the nbr's shortest dist gets updated agin put it into set
                if(nodeDist+nbrDist<dist[nbrNode]) {
                    auto it = st.find({dist[nbrNode],nbrNode});
                    if(it!=st.end()) {
                        st.erase(it);
                    }
                    dist[nbrNode] = nodeDist+nbrDist;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        //minimum time to reach all nodes will be the max value of the shortest dist to all
        //nodes, if anyone is unreachable return -1 for it
        int maxi = *max_element(dist.begin(),dist.end());
        return maxi==INT_MAX?-1:maxi;
    }
};