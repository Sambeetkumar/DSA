#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        //hashing array elements with its index
        m[nums[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        //finding rem value which gives the target value, when added with current element
        int rem = target - nums[i];

        /* it is present in the map and at a index diff from current index, then we have found
        a required pair*/
        auto it = m.find(rem);
        if (it != m.end() && it->second != i)
        {
            return {i, it->second};
        }
    }
    return {0, 0};
}
int main(int argc, char *argv[])
{
    vector<int> v = {3, 2, 4};
    vector<int> res = twoSum(v, 6);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}