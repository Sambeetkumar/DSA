#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/single-element-in-a-sorted-array/

int singleNonDuplicate(vector<int> &nums)
{
    //if there is only one element in the array
    if (nums.size() == 1)
        return nums[0];

    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        //edge case - if mid lands on 0th index of (n-1)th index
        if (mid == 0 || mid == nums.size() - 1)
        {
            return nums[mid];
        }

        //if mid lands on the single element
        else if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        else if ((mid & 1) == 0) // mid lands on even index
        {
            if (nums[mid] == nums[mid - 1])
                e = mid - 2;
            else
                s = mid + 2;
        }
        else // mid lands on odd index
        {
            if (nums[mid] == nums[mid - 1])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(v);
    return 0;
}