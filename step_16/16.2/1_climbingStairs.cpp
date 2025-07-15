#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveUsingRec(int n)
    {
        if(n==0 || n==1)
        return 1;//1 way milgya end mai pahuchne ke lie

        int oneStep = solveUsingRec(n-1);
        int twoStep = solveUsingRec(n-2);

        return oneStep+twoStep;
    }
    int solveUsingDp(int n,vector<int> &dp)
    {
        if(n==0 || n==1)
        return 1;//1 way milgya end mai pahuchne ke lie

        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int oneStep = solveUsingDp(n-1,dp);
        int twoStep = solveUsingDp(n-2,dp);
        
        dp[n]=oneStep+twoStep;
        return dp[n];
    }
    int tabulation(int n)
    {
        //step1
        vector<int> dp(n+1,-1);
        //step2
        dp[0]=1;
        dp[1]=1;
        //step3
        for(int i=2; i<=n; i++)
        {
            int oneStep = dp[i-1];
            int twoStep = dp[i-2];
        
            dp[i]=oneStep+twoStep;
        }
        return dp[n];
    }
    int spaceOptimised(int n)
    {
        //step2
        int prev=1;
        int nextPrev=1;
        //step3
        for(int i=2; i<=n; i++)
        {
            int oneStep = prev;
            int twoStep = nextPrev;
        
            int curr=oneStep+twoStep;
            //shifting
            nextPrev=prev;
            prev=curr;
        }

        return prev;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return spaceOptimised(n);
    }
};