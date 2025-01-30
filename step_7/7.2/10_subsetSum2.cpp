#include <bits/stdc++.h>
using namespace std;
void generate(vector<vector<int>> &res, vector<int> v, vector<int> arr, int ind)
{
  res.push_back(v);
  if (ind == arr.size())
  {
    return;
  }
  for (int i = ind; i < arr.size(); i++)
  {
    if (i > ind && arr[i] == arr[i - 1])
      continue;
    v.push_back(arr[i]);
    generate(res, v, arr, i + 1);
    v.pop_back();
  }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  vector<int> v;
  generate(res, v, nums, 0);
  return res;
}
int main(int argc, char *argv[])
{
  vector<int> v = {1, 2, 2, 3, 3, 3, 4, 5};
  vector<vector<int>> ans = subsetsWithDup(v);
  for (auto it : ans)
  {
    for (auto it2 : it)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }

  return 0;
}