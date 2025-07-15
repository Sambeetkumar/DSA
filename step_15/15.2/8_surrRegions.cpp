#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
  **** A region that can't be surrounded will have atleast one edge 'O' cell ****
  the idea is to visit all the cells that can be reached from 'O' cell present on the
  edge. so consider all the 'O' cells present on the edge as source and perform bfs/dfs
  .By doing this all the regions that are connected to the edge will be visited and the
  regions that are not connected to any edge will remain unvisited
*/
    void dfs(vector<vector<char>>& board,vector<vector<bool>> &visited,int m,int n,int i,int j)
    {
        visited[i][j]=true;
        if(i+1<m && board[i+1][j]=='O' && !visited[i+1][j])//extend down
        {
            dfs(board,visited,m,n,i+1,j);
        }
        if(i-1>=0 && board[i-1][j]=='O' && !visited[i-1][j])//extend up
        {
            dfs(board,visited,m,n,i-1,j);
        }
        if(j+1<n && board[i][j+1]=='O' && !visited[i][j+1])//extend right
        {
            dfs(board,visited,m,n,i,j+1);
        }
        if(j-1>=0 && board[i][j-1]=='O' && !visited[i][j-1])//extend left
        {
            dfs(board,visited,m,n,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //search for 'O' in firstRow and lasRow and perfomr dfs if unvisited
        for(int j=0; j<n; j++)
        {
            if(board[0][j]=='O' && !visited[0][j])
            dfs(board,visited,m,n,0,j);
            if(board[m-1][j]=='O' && !visited[m-1][j])
            dfs(board,visited,m,n,m-1,j);
        }
        //search for 'O' in first and last col and perform dfs if unvisited
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
            dfs(board,visited,m,n,i,0);
            if(board[i][n-1]=='O' && !visited[i][n-1])
            dfs(board,visited,m,n,i,n-1);
        }
        //now if there is any 'O' left that is unmarked, it means these 'O's can't
        //be reached from the edge, mark them as 'X'
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                board[i][j]='X';
            }
        }
    }
};