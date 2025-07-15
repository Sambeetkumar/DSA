#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //build distance distance matrix
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        //initialise the distance matrix
        for(auto it:edges){
            int i=it[0];
            int j=it[1];
            int wt=it[2];
            dist[i][j]=wt;
            dist[j][i]=wt;
        }
        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }
        //perform floyd warshal algo to compute shortest dist between every two node
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                if(i==k) continue;
                for(int j=0; j<n; j++){
                    if(j==k) continue;
                    dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        //find the node with min nbrs at a threshold dist
        int ans=-1;
        int nodeCnt=n;
        for(int i=0; i<n; i++){
            //for each node determine howmany nbrs are in threshold distance
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            //update the node with min nbrs at a threshold dist
            if(cnt<=nodeCnt){
                nodeCnt=cnt;
                ans=i;
            }
        }
        return ans;
    }
};