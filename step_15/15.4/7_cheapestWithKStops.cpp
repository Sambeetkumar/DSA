#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
/*the idea is to give stops more priority, lessers stops will be processed first. A queue will be fine
because we are starting from stops 0 and and stops will increase by 1 so all the entries in queue
will automatically be arranged in non_decreasing order os stops*/
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0; i<flights.size(); i++)
        {
            adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        //dist
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        //stops-node-cost
        queue<vector<int>> q;
        //initially push src with 0 stops and 0 cost
        q.push({0,src,0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int stops = front[0];
            int node = front[1];
            int cost = front[2];
            //break when stops exceed the limit for any entry bcoz for all the rest entries in q
            //stops will be equal or more
            if(stops>k) break;
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                int nbrCost = nbr.second;
                if(cost+nbrCost<dist[nbrNode]){
                    dist[nbrNode]=cost+nbrCost;
                    //while pushing increase the stop by 1
                    q.push({stops+1,nbrNode,dist[nbrNode]});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};