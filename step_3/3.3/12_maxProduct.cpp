#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;//stores latest maximum product
        int prefixSum = 1;//stores nonzero product starting from left
        int suffixSum = 1;//stores nonzero product starting from right
        for(int i=0; i<n; i++)
        {
            /*if preSum or suffixSum becomes zero then reset it to 1 otherwise it
            will be always 0 if we multiply any next number to it*/
            if(prefixSum == 0) prefixSum = 1;
            if(suffixSum == 0) suffixSum = 1;
            //updating prefixSum, suffixSum and maximum sum(if possible)
            prefixSum *= nums[i];
            suffixSum *= nums[n-i-1];
            maxi = max(maxi,max(prefixSum,suffixSum));
        }
        return maxi;
    }
int main(int argc, char* argv[]) {
    vector<int> v = {1, 2, 3, 0, 1, -2, 128, 0, 3, 2, 1};
    cout << maxProduct(v);
    return 0;
}