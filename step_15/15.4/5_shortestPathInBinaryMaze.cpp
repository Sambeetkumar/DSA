#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void addNbr(int cr,int cc,vector<int> &r,vector<int> &c,int m,int n,vector<vector<int>>& grid, vector<vector<int>> &visited,queue<pair<int,int>> &q)
    {
        for(int i=0; i<8; i++){
            int newr = cr+r[i];
            int newc = cc+c[i];
            //if new pos is suitable then push is into queue
            if(newr>=0 && newr<m && newc>=0 && newc<n && !visited[newr][newc] &&
            grid[newr][newc]==0)
            {
                visited[newr][newc]=1;
                q.push({newr,newc});
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       //edge case
       if(grid[0][0] || grid[m-1][n-1]) return -1;
       vector<vector<int>> visited(m,vector<int>(n,0));
       queue<pair<int,int>> q;
       //vectors that will help in movement in all 8 directions
       vector<int> r={-1,-1,-1,0,0,1,1,1};
       vector<int> c={-1,0,1,-1,1,-1,0,1};
       //initialising q and visited matrix
       q.push({0,0});
       visited[0][0]=1;
       int cnt=1;
       //perform bfs and move in all possible directions
       while(!q.empty()){
         int s = q.size();
         //we are popping level wise to keep track of count
         for(int i=0; i<s; i++)
         {
            auto it = q.front();
            q.pop();
            int currRow = it.first;
            int currCol = it.second;
            //if we have reached at last node
            if(currRow==m-1 && currCol==n-1)
            return cnt;
            addNbr(currRow,currCol,r,c,m,n,grid,visited,q);
         }
         cnt++;
       }
       return -1;
    }
};