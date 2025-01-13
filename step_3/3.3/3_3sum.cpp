#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());//sorting given array
    int n = nums.size();
    //pointing first pointer i to the first element
    for (int i = 0; i < n; i++)
    {
        //when we have found all triplet pointed by i, move i untill i points to a diff el
        if (i != 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        //pointing 2nd pointer j to the el next to i and k to the last element
        int j = i + 1, k = n - 1;
        while (j < k)
        {

            int sum = nums[i] + nums[j] + nums[k];//finding sum pointed by i,j and k
            if (sum == 0)
            {   //if sum ==0 we have found a triplet push it
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;//increase j until it points to a diff el
                }
                k--;
                while (k > j && nums[k] == nums[k + 1])
                {
                    k--;//decrease k until it points to a diff el
                }
            }
            else if (sum < 0)//if sum<0 then to increase the sum move j to right
            {
                j++;
            }
            else//if sum>0 to decrease the sum move k to left
            {
                k--;
            }
        }
    }
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> v = {4, 1, 6, 3, -4, -2, -2, 0, 0, 0};
    vector<vector<int>> res = threeSum(v);
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