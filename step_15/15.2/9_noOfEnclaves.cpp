#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//same approach as leeetcode 130
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int m,int n,int i,int j,vector<int> &delRow,vector<int> &delCol)
    {
        visited[i][j]=true;
        for(int k=0; k<4; k++)
        {
            int nRow = i+delRow[k];
            int nCol = j+delCol[k];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1 && !visited[nRow][nCol]) {
                dfs(grid,visited,m,n,nRow,nCol,delRow,delCol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,-1,0,1};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //search for 1(land cell) in firstRow and lasRow
        for(int j=0; j<n; j++)
        {
            if(grid[0][j]==1 && !visited[0][j])
            dfs(grid,visited,m,n,0,j,delRow,delCol);
            if(grid[m-1][j]==1 && !visited[m-1][j])
            dfs(grid,visited,m,n,m-1,j,delRow,delCol);
        }
        //search for 1(land cell) in first and last col
        for(int i=0; i<m; i++)
        {
            if(grid[i][0]==1 && !visited[i][0])
            dfs(grid,visited,m,n,i,0,delRow,delCol);
            if(grid[i][n-1]==1 && !visited[i][n-1])
            dfs(grid,visited,m,n,i,n-1,delRow,delCol);
        }
        //now if there is any 1(land cell) left that is unmarked,
        //it means these land cells can't be reached from the edge, count them
        int cnt=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                cnt++;
            }
        }
        return cnt; 
    }
};