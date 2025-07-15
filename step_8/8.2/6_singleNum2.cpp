#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//Optimal solution O(N) complexity - remember the solution
    // int singleNumber(vector<int>& nums) {
    //     int ones = 0;
    //     int twos = 0;
    //     for(int i=0; i<nums.size(); i++){
    //         ones = (ones^nums[i])&(~twos);
    //         twos = (twos^nums[i])&(~ones);
    //     }
    //     return ones;
    // }
    int singleNumber(vector<int>& nums) {
       if(nums.size()==1) return nums[0];
       sort(nums.begin(),nums.end());
       for(int i=1; i<nums.size(); i+=3){
         if(nums[i]!=nums[i-1])
         return nums[i-1];
       }
       return nums.back();
    }
};