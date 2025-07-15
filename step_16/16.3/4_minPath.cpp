#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int so(vector<vector<int>>& grid,int m,int n)
    {
        vector<int> nextRow(n,0);
        vector<int> currRow(n,0);
        //base case- store ans for nextRow
        /*we are calculating the cost to reach at final pos for each el in the last
        row*/
        nextRow[n-1]=grid[m-1][n-1];
        for(int j=n-2; j>=0; j--)
        {
            nextRow[j] = grid[m-1][j]+nextRow[j+1];
        }

        //reverse looping
        for(int i=m-2; i>=0; i--)//ans for last row is already calculated
        {
            for(int j=n-1; j>=0; j--)
            {
                int r=INT_MAX,b=INT_MAX;
                if(j+1<n)
                r=currRow[j+1];
                if(i+1<m)
                b=nextRow[j];
                //choose the min cost that we get from right or bottom and add to
                //current cell cost
                currRow[j]= grid[i][j]+min(r,b);
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return so(grid,m,n);
    }
};