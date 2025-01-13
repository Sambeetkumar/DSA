#include <bits/stdc++.h>
using namespace std;
//same approach as 3 sum, just add one more pointer
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int l = 0; l < n; l++)
    {
        if (l != 0 && nums[l] == nums[l - 1])
        {
            continue;
        }
        for (int i = l+1; i < n-2; i++)
        {
            if (i != l+1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k)
            {

                int sum = nums[l]+ nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    ans.push_back({nums[l],nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    k--;
                    while (k > j && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main(int argc, char *argv[])
{   vector<int> v = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> res = fourSum(v,0);
    for (auto it : res)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}