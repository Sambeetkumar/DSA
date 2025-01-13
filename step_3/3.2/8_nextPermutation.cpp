#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int temp = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        /*start iterating from the end and store the index i where el pointed by i is strictly
        smaller than el pointed by i+1*/
        if (nums[i] < nums[i + 1])
        {
            temp = i;
            break;
        }
    }
    //if temp == -1, then this is the last permuation
    if (temp == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    /*starting from end, iterate upto index i and swap the values if you encounter a value
    greater than value pointed by temp*/
    for (int i = n - 1; i > temp; i--)
    {
        if(nums[i]>nums[temp])
        {
            swap(nums[i], nums[temp]);
            break;
        }
    }
    //reverse the sub array starting from temp+1 to end 
    reverse(nums.begin() + temp + 1, nums.end());
    for(auto it:nums)
    {
        cout << it << " ";
    }
}
int main(int argc, char *argv[])
{
    vector<int> v = {3, 5, 7, 4};
    nextPermutation(v);
    return 0;
}