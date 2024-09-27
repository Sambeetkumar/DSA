#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/find-peak-element/description/

//Optimal approach O(log n) time complexity
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1) //if size of array is one, then that is the peak
    return 0;

    if(nums[0]>nums[1]) //if the starting index is the peak
    return 0; 

    if(nums[n-1]>nums[n-2]) //if the ending index is the peak
    return n - 1;

    /*initialized starting to 1 index and ending to n-2 index,
    to avoid error while comparing mid with its previous and next element*/
    int s = 1, e = n-2;
    while(s<=e)
    {
        int mid = (s + e) / 2;

        //if mid lands on the peak
        if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1])
        return mid;

        //if mid is on the increasing slope then peak is on the right, so eliminate the left half
        else if(nums[mid]>nums[mid-1])
            s = mid + 1;

        //eliminate the right half
        else
            e = mid - 1;
    }
    return -1;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1,2,4,3,6,7,3};
    cout << findPeakElement(v);
    return 0;
}

// brute force approach O(n) complexity

// int findPeakElement(vector<int> &nums)
// {

//     if (nums.size() == 1)
//         return 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i == 0)
//         {
//             if (nums[i] > nums[i + 1])
//                 return i;
//         }
//         else if (i == nums.size() - 1)
//         {
//             if (nums[i] > nums[i - 1])
//                 return i;
//         }
//         else
//         {
//             if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//                 return i;
//         }
//     }
//     return -1;
// }