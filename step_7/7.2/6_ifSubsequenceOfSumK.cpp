#include <bits/stdc++.h>
using namespace std;
bool kSum(vector<int> a, int sum, int i, int target)
{
    if (i == a.size())
    {
        if (sum == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //if there are any subsequence in left recursion tree, return true no need to do further
    //recursion
    if (kSum(a, sum, i + 1, target))
        return true;
    sum += a[i];
    //if there are any subsequence in right recursion tree, return true no need to do further
    //recursion
    if (kSum(a, sum, i + 1, target))
        return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return kSum(a, 0, 0, k);
}
int main(int argc, char *argv[])
{
    vector<int> arr = {4, 2, 5, 6, 7};
    cout << isSubsetPresent(5, 14, arr);

    return 0;
}