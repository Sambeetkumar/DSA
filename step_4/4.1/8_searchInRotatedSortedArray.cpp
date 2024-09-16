#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/description/

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    while(s<=e)
    {
        int mid = (s + e) / 2;

        //check if mid is pointing to target or not.
        if(nums[mid]==target)
        return mid;

        //if mid is not pointing to the target then find the half which is sorted
        else if(nums[s]<=nums[mid])
        {
            //if target is present in the sorted half then reduce the search space to sorted part
            if(target>=nums[s] && target <= nums[mid])
                e = mid - 1;
            else
            //if target is not present in the sorted part then reduce the search space to other half
                s = mid + 1;
        }
        else
        {
            ////if target is present in the sorted half then reduce the search space to sorted part
            if(target>=nums[mid] && target <= nums[e])
                s = mid + 1;
            else
            ////if target is not present in the sorted part then reduce the search space to other half
                e = mid - 1;
        }
    }
    return -1;
}
int main(int argc, char* argv[]) {
    vector<int> v = {1};
    cout << search(v,0);

    return 0;
}