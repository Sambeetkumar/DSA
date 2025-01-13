#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    /*bs range will be max el and sum of all el as sub array with maximum sum is array itself*/
    int s = *max_element(nums.begin(), nums.end());
    int e = accumulate(nums.begin(), nums.end(), 0);

    while (s <= e)
    {
        /*mid is the capacity of subarray sum*/
        int mid = s + (e - s) / 2;
        int sum = 0, count = 1;
        for (int j = 0; j < n; j++)
        {
            /*if adding nums[j] to sum goes beyond capacity create
             a partition and assign nums[j] to sum*/
            if (sum + nums[j] > mid)
            {
                sum = nums[j];
                count++;
            }
            else
            {
                sum += nums[j];
            }
        }
        /*if number of subarray is less than required, we need to decrease our capacity*/
        if (count <= k)
            e = mid - 1;
        else
        //else increase capacity
            s = mid + 1;
    }
    return s;
}
int main(int argc, char *argv[])
{
    vector<int> v = {7, 2, 5, 10, 8};
    cout << splitArray(v, 2);

    return 0;
}