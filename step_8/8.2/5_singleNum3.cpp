#include <bits/stdc++.h>
using namespace std;
//soltuin using concept of buckets
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr=0;
        for(int it:nums){
            xr^=it;
        }
        //find the rightmost bit at which the two single numbers differ
        /*and based on that we will create 2 buckets, the numbers who bit is set at that
        bit will go to one bucket and the others will go to the other bcuket. in this way
        the different numbers will lie in different bucket and all occurrences of repated
        numebrs will either lie in b1 or b2. example if first 7 goes to b1 then second 7 will
        algo go to b2*/
        int rightMost = (xr&(xr-1))^xr;
        int b1=0,b2=0;
        for(int i=0; i<nums.size(); i++){
            if(rightMost&nums[i]){
                b1^=nums[i];
            }
            else{
                b2^=nums[i];
            }
        }
        return {b1,b2};
    }
};