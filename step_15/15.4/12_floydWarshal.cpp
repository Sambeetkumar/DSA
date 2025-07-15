#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        /*the idea is to check for every pivot k from 0 to n-1, break dist[i][j] to
        dist[i][k]+dist[k][j] if possible update the distance*/
        int v = dist.size();
        for(int k=0; k<v; k++){
            for(int i=0; i<v; i++){
                if(i==k) continue;//skip the pivot row
                for(int j=0; j<v; j++){
                    if(j==k) continue;//skip the pivot col
                    //check whether all the broken weights exist or not
                    if(dist[i][k]!=1e8 && dist[k][j]!=1e8){
                      dist[i][j] = min(dist[i][j],
                      dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        //if there is neg cycle
        // for(int i=0; i<v; i++){
        //     if(dist[i][i]<0){
        //         cout<<"Negative cyle is present"
        //     }
        // }
    }
};