#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveUsingRec(int m,int n,int i,int j)
    {
        if(i==m-1 && j==n-1)
        return 1;//reached at final pos return 1

        int r=0,b=0;
        if(j+1<n)//if possible go right
        r=solveUsingRec(m,n,i,j+1);
        if(i+1<m)//if possible go down
        b=solveUsingRec(m,n,i+1,j);

        return r+b;//return the tot path explore by right and bottom
    }
    int solveUsingDp(int m,int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i==m-1 && j==n-1)
        return 1;

        if(dp[i][j]!=-1) {
        return dp[i][j];
        }
        int r=0,b=0;
        if(j+1<n)
        r=solveUsingDp(m,n,i,j+1,dp);
        if(i+1<m)
        b=solveUsingDp(m,n,i+1,j,dp);
        
        dp[i][j]=r+b;
        return dp[i][j];
    }
    int tab(int m,int n)
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //base case - reached at finish line
        dp[m-1][n-1] = 1;

        //reverse looping
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i==m-1 && j==n-1) continue;//base case(already calulated)
                int r=0,b=0;
                if(j+1<n)
                r=dp[i][j+1];
                if(i+1<m)
                b=dp[i+1][j];
        
                dp[i][j]=r+b;
            }
        }
        return dp[0][0];
    }
    //observe from tab that ans of any cell depends on adj cell on next row and adj cell
    //on next col, so we can solve it using two row vectors
    int so(int m,int n)
    {
        //ans for each last row cell will be 1 as there is 
        //only one option to go right to each at final pos
        vector<int> nextRow(n,1);
        vector<int> currRow(n,0);

        //reverse looping
        for(int i=m-2; i>=0; i--)//ans for last row is already calculated
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i==m-1 && j==n-1) {
                    continue;
                }
                int r=0,b=0;
                if(j+1<n)
                r=currRow[j+1];
                if(i+1<m)
                b=nextRow[j];
        
                currRow[j]=r+b;
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return so(m,n);
    }
};