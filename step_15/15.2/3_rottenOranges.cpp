#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        //initially push all the rotten orange positions
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int cnt=0;
        //perform bfs
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0; i<s; i++)
            {
                pair<int,int> temp = q.front();
                q.pop();
                if(temp.first+1<m && grid[temp.first+1][temp.second]==1)
                {
                    grid[temp.first+1][temp.second]=2;//mark the visited oranges as rotten
                    q.push({temp.first+1,temp.second});
                }
                if(temp.first-1>=0 && grid[temp.first-1][temp.second]==1)
                {
                    grid[temp.first-1][temp.second]=2;
                    q.push({temp.first-1,temp.second});
                }
                if(temp.second+1<n && grid[temp.first][temp.second+1]==1)
                {
                    grid[temp.first][temp.second+1]=2;
                    q.push({temp.first,temp.second+1});
                }
                if(temp.second-1>=0 && grid[temp.first][temp.second-1]==1)
                {
                    grid[temp.first][temp.second-1]=2;
                    q.push({temp.first,temp.second-1});
                }
            }
            cnt++;
        }
        //lastly check is there is any fresh orange left
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return cnt==0?0:cnt-1;
    }
};