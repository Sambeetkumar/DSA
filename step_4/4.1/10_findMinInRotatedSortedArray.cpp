#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1, min = INT32_MAX;
    while(s<=e)
    {
        int mid = (s + e) / 2;
        //if the search space is sorted
        if(nums[s]<=nums[e])
        {
            /* compare the minimum element with the prev minimum,
            if it is smaller then store the minimum element and break*/
            if(min>nums[s])
            min = nums[s];
            
            break;
        }
        //if the left half is sorted
        else if(nums[s]<=nums[mid])
        {
            /* compare the minimum element with the prev minimum,
            if it is smaller, then store the minimum element*/
            if(min>nums[s])
            min = nums[s];

            s = mid + 1; //eliminate the left half
        }
        else//if the right half is sorted
        {
            /* compare the minimum element with the prev minimum,
            if it is smaller, then store the minimum element */
            if(min>nums[mid])
            min = nums[mid];
            
            e = mid - 1; //eliminate the right half
        }
    }

    return min;

    }
int main(int argc, char* argv[]) {
    vector<int> v = {3,1,2};
    cout << findMin(v);
    return 0;
}