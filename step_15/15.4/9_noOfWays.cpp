#include <bits/stdc++.h>
using namespace std;
class Solution {
    int modu = 1e9+7;
public:
    int modAdd(long long a, long long b){
        return (a+b)%modu;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0; i<roads.size(); i++){
            adjList[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        //{minimum time --- no of ways to reach in minimum time}
        vector<pair<long long,long long>> dist(n,{LLONG_MAX,0});
        //minTime-node
        set<pair<long long,int>> st;
        //initial case
        st.insert({0,0});
        dist[0]={0,1};
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(st.begin());
            int node = it.second;
            long long nodeDist = it.first;
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                long long nbrDist = (long long)nbr.second;
                //if we discover a shorter path to the nbr
                if(nodeDist+nbrDist<dist[nbrNode].first){
                    //1 - erase the old entry
                    auto search = st.find({dist[nbrNode].first,nbrNode});
                    if(search!=st.end()){
                        st.erase(search);
                    }
                    //2- update it's min cost in distance array
                    dist[nbrNode].first = nodeDist+nbrDist;
                    //3- replace the path cnt of nbr as they will be of no use
                    dist[nbrNode].second = dist[node].second;
                    //4- insert the new entry
                    st.insert({dist[nbrNode].first,nbrNode});
                }
                //if we discover a path in the same cost as nbr's min cost
                //it will contribute to number of existing paths
                else if(nodeDist+nbrDist==dist[nbrNode].first){
                    dist[nbrNode].second = modAdd(dist[nbrNode].second,dist[node].second);
                }
            }
        }
        return dist[n-1].second;
    }
};