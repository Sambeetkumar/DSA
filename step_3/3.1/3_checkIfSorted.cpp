#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            count++;
            if (count > 1)
                return false;
        }
    }
    if (count == 0)
        return true;
    else
    {
        if (nums[n - 1] <= nums[0])
            return true;
        else
            return false;
    }
}
int main(int argc, char *argv[])
{
    vector<int> v = {1,2,3,4};
    cout << check(v);

    return 0;
}