#include <bits/stdc++.h>
using namespace std;
void generate(vector<vector<int>> &ans, vector<int> v, vector<int> arr, int ind, int target)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    /*if any element is repeated in the array considering any one of them will generate the same
    subsequence, so what we are doing is if any el is repeated we will only consider the first one,
    for the rest we will not generate recursion call*/
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        v.push_back(arr[i]);
        generate(ans, v, arr, i + 1, target - arr[i]);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    generate(ans, v, candidates, 0, target);
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1,1,2,2,2,5,7};
    vector<vector<int>> ans = combinationSum2(v, 9);
    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout << it2;
        }
        cout << endl;
    }
    return 0;
}