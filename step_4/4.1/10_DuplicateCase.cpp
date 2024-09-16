#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int s = 0, e = nums.size() - 1, min = INT32_MAX;
    while(s<=e)
    {
        int mid = (s + e) / 2;
        if(nums[s]==nums[mid] && nums[mid]==nums[e])
        {
            if(min>nums[mid])
            min = nums[mid];
            
            s=s+1,e=e-1;
        }
        else if(nums[s]<=nums[mid])
        {
            if(min>nums[s])
            min = nums[s];

            s = mid + 1;
        }
        else
        {
            if(min>nums[mid])
            min = nums[mid];
            
            e = mid - 1; 
        }
    }

    return min;

    }
int main(int argc, char* argv[]) {
    vector<int> v = {1,0,1,1,1};
    cout << findMin(v);
    return 0;
}