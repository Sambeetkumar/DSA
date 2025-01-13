#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> f(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        f[nums[i]] = true;
    }
    for (int i = 0; i<f.size(); i++)
    {
        if(f[i]==false)
        return i;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    vector<int> v = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(v);

    return 0;
}