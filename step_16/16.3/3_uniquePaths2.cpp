#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//same as unique path but check if whether we can move or not
    int solveUsingDp(vector<vector<int>>& obstacleGrid,int m,int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
        {
            //if the finish point contains obstacle, it is impossible to reach
            if(obstacleGrid[i][j]==0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int r = 0, b = 0;
        if (j + 1 < n && obstacleGrid[i][j+1]==0)
            r = solveUsingDp(obstacleGrid, m, n, i, j + 1, dp);
        if (i + 1 < m && obstacleGrid[i+1][j]==0) 
            b = solveUsingDp(obstacleGrid, m, n, i + 1, j, dp);

        dp[i][j] = r + b;
        return dp[i][j];
    }
    int so(vector<vector<int>>& obstacleGrid,int m,int n)
    {
        vector<int> nextRow(n,0);
        vector<int> currRow(n,0);
        //base case
        /*for the last row move from right to left and mark 1 untill no stone
        is found, because if stone is found, then for rest of the indices it is
        impossible to visit the finish line*/
        for(int i=n-1; i>=0; i--)
        {
            if(obstacleGrid[m-1][i]==1) {
                break;
            }
            nextRow[i]=1;
        }
        //reverse looping
        for(int i=m-2; i>=0; i--)//ans for last row is already calculated
        {
            for(int j=n-1; j>=0; j--)
            {
                if(obstacleGrid[i][j]==1) {
                    currRow[j]=0;
                    continue;
                }
                int r=0,b=0;
                if(j+1<n && obstacleGrid[i][j+1]==0)
                r=currRow[j+1];
                if(i+1<m && obstacleGrid[i+1][j]==0)
                b=nextRow[j];
        
                currRow[j] = (long long)r;
                currRow[j] += (long long)b; 
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //if starting pos contains stone we can't start at all
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return so(obstacleGrid,m,n);
    }
};