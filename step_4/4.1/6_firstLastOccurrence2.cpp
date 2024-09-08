#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

vector<int> searchRange(vector<int>& nums, int target) {
    //uses lower_bound stl function to find element >= target
    int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    //uses uper_bound stl function to find element > target
    int end = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    

    /*if start==nums.size(), then target is greater than the largest element
    if nums[start] != target, then target is smaller than the smallest element in the array
    or it is not present in the array*/
    if(start==nums.size() || nums[start] != target)
        return {-1,-1};
    else
        return {start, end - 1};
    }
int main(int argc, char* argv[]) {
    vector<int> v = {};
    
    cout << searchRange(v, 0).at(0)<<endl;
    cout << searchRange(v, 0).at(1)<<endl;

    return 0;
}