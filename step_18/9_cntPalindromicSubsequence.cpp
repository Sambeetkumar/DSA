#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*You are required to complete below method */
    int solve(string &s, vector<vector<int>> &dp,int i,int j){
        if(i==j)
        return 1;
        if(i>j)
        return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==s[j]){
            dp[i][j]=1+solve(s,dp,i+1,j)+solve(s,dp,i,j-1);
        }
        else
        {
            dp[i][j]=(solve(s,dp,i+1,j)+solve(s,dp,i,j-1)-solve(s,dp,i+1,j-1));
        }
        return dp[i][j];
    }
    int countPS(string &s) {
        // Your code here
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,dp,0,n-1);
    }
};