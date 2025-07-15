#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveUsingRec(vector<vector<int>>& triangle,int i,int j)
    {
        if(i>=triangle.size()) {
            return 0;
        }
        int l=solveUsingRec(triangle,i+1,j);
        int r=solveUsingRec(triangle,i+1,j+1);
        //choose the minimum from left and rightmovement
        return triangle[i][j]+min(l,r);
    }
    int tabulation(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for(int i=m-1; i>=0; i--)
        {
            //as we are moving in a triangle, for any rowInd i,the max colInd is i
            for(int j=i; j>=0; j--)
            {
               int l=dp[i+1][j];
               int r=dp[i+1][j+1];
               
               dp[i][j] = triangle[i][j] + min(l,r);
            }
        }
        return dp[0][0];
    }
    int so(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<int> nextRow(m,0);
        vector<int> currRow(m,0);
        //base case - the value of nextRow will be same as lastRow of the traingle
        for(int i=m-1; i>=0; i--)
        {
            nextRow[i]=triangle[m-1][i];
        }
        
        //m-1th row is alreasy calculated so start from second last row
        for(int i=m-2; i>=0; i--)
        {
            //as we are moving in a triangle, for any rowInd i,the max colInd is i
            for(int j=i; j>=0; j--)
            {
               int l=nextRow[j];
               int r=nextRow[j+1];
               
               currRow[j] = triangle[i][j] + min(l,r);
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return so(triangle);
    }
};