#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solveUsingRec(vector<vector<int>>& arr,int ind,int lastInd)
    {
        if(ind>=arr.size())
        return 0;
        
        int ans=0;
        for(int i=0; i<3; i++)
        {
            if(i!=lastInd)//can't repeat the last activity
            {
                //store the combination that gives maximum value
                ans=max(ans,arr[ind][i]+solveUsingRec(arr,ind+1,i));
            }
        }
        return ans;
    }
    int solveUsingDp(vector<vector<int>>& arr,int ind,int lastInd,vector<vector<int>> &dp)
    {
        if(ind>=arr.size())
        return 0;
        
        if(dp[ind][lastInd+1]!=-1)//if ans is already calculated
        {
            return dp[ind][lastInd+1];
        }
        int ans=0;
        for(int i=0; i<3; i++)
        {
            if(i!=lastInd)
            {
                ans=max(ans,arr[ind][i]+solveUsingDp(arr,ind+1,i,dp));
            }
        }
        dp[ind][lastInd+1] = ans;
        return ans;
    }
    int tab(vector<vector<int>>& arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(4,0));
        
        for(int ind=n-1; ind>=0; ind--)//rev ind n-1->0
        {
            for(int lastInd=2; lastInd>=-1; lastInd--)//rev lastInd 2->-1
            {
                int ans=0;
                for(int i=0; i<3; i++)
                {
                  if(i!=lastInd)
                  {
                    //shift cols by +1 for valid indexing
                    ans=max(ans,arr[ind][i]+dp[ind+1][i+1]);
                  }
                }      
                dp[ind][lastInd+1] = ans;//shift cols by +1 for valid indexing
            }
        }
        //answer will be stored at 0th index and -1lastInd but -1is represented by 0th col
        return dp[0][0];
    }
    //from tab we can observe that ans of any row depends on next row
    //so we can use only two row vectors to solve the problem, instead of using grid
    int so(vector<vector<int>>& arr)
    {
        int n = arr.size();
        vector<int> nextRow(4,0);
        vector<int> currRow(4,0);
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int lastInd=2; lastInd>=-1; lastInd--)
            {
                int ans=0;
                for(int i=0; i<3; i++)
                {
                  if(i!=lastInd)
                  {
                    ans=max(ans,arr[ind][i]+nextRow[i+1]);
                  }
                }      
                currRow[lastInd+1] = ans;
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return so(arr);
    }
};