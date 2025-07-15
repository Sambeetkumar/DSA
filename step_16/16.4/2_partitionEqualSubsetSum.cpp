#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//try to achieve the halfSum by including/excluding principle
    bool solveUsingRec(vector<int>& nums, int ind, int sum) {
        if (ind == nums.size()) {
            return sum == 0;
        }

        bool inc = false, ex = false;
        if (nums[ind] <= sum) {
            inc = solveUsingRec(nums, ind + 1, sum - nums[ind]);
        }
        ex = solveUsingRec(nums, ind + 1, sum);
        //if either of inc or ex gives true return true (there exist a subset with halfSum)
        return inc || ex;
    }
    int tabulation(vector<int>& nums) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if (totSum & 1)
            return false;
        int halfSum = totSum / 2;
        // taking index as row and halfSum as col
        vector<vector<bool>> dp(n + 1, vector<bool>(halfSum + 1, false));
        // base case
        dp[n][0] = true;
        // reverse looping
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int sum = 0; sum <= halfSum; sum++) {
                bool inc = false, ex = false;
                if (nums[ind] <= sum) {
                    inc = dp[ind + 1][sum - nums[ind]];
                }
                ex = dp[ind + 1][sum];

                dp[ind][sum] = inc || ex;
            }
        }
        return dp[0][halfSum];
    }
    int so(vector<int>& nums) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if (totSum & 1)
            return false;
        int halfSum = totSum / 2;
        // taking two row vectors
        vector<bool> currRow(halfSum+1, false);
        vector<bool> nextRow(halfSum+1, false);
        // base case
        nextRow[0] = true;
        // reverse looping
        for (int ind = n-1; ind >= 0; ind--) {
            for (int sum = 0; sum <= halfSum; sum++) {
                bool inc = false, ex = false;
                if (nums[ind] <= sum) {
                    inc = nextRow[sum - nums[ind]];
                }
                ex = nextRow[sum];

                currRow[sum] = inc || ex;
            }
            // row shifting
            nextRow = currRow;
        }
        return nextRow[halfSum];
    }
    int so2(vector<int>& nums) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if (totSum & 1)
            return false;
        int halfSum = totSum / 2;
        // taking one row vectors
        vector<bool> currRow(halfSum+1, false);
        // base case
        currRow[0] = true;
        // reverse looping
        for (int ind = n-1; ind >= 0; ind--) {
            //reversed the inner loop
            for (int sum = halfSum; sum >= 0; sum--) {
                bool inc = false, ex = false;
                if (nums[ind] <= sum) {
                    inc = currRow[sum - nums[ind]];
                }
                ex = currRow[sum];

                currRow[sum] = inc || ex;
            }
        }
        return currRow[halfSum];
    }
    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if (totSum & 1)
            return false;
        return so2(nums);
    }
};