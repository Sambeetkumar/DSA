#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/search-insert-position/

int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1,ans=-1;

        while(low<=high)
        {

            int mid=low+((high-low)/2);
            if(nums[mid]==target)
            //if target is found return the index
            return mid;
            else if(nums[mid]>target)
            //shrinking array to left of mid
            high=mid-1;
            else
            //if the number pointed by mid is less than target then store the index
            //shrinking array to the right of mid
            {
                ans=mid;
                low=mid+1;
            }
        }
        //returning the index just after floor(target)
        return ans+1;
        
    }

int main(int argc, char* argv[]) {
    vector<int> v = {1, 3, 5, 6};
    cout << searchInsert(v, 5)<<endl;
    cout << searchInsert(v, 2)<<endl;
    cout << searchInsert(v, 7)<<endl;
    return 0;
}