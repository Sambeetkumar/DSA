#include <bits/stdc++.h>
using namespace std;
void generateSubset(vector<int> &nums, int ind, vector<int> v, vector<vector<int>> &ans)
{
    // if we reach the end of nums, push v to ans and return
    if (ind == nums.size())
    {
        ans.push_back(v);
        return;
    }
    // generate subsets without including nums[ind]
    generateSubset(nums, ind + 1, v, ans);
    // generate subsets including nums[ind]
    v.push_back(nums[ind]);
    generateSubset(nums, ind + 1, v, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans; // to store the result, we will pass it by reference
    vector<int> v;
    generateSubset(nums, 0, v, ans);
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    for(auto it:subsets(nums))
    {
        for(auto it:it)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}