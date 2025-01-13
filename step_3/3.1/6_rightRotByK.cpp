#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.begin() + n);
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin()+(k+1), nums.end());
    for (auto it : nums)
    {
        cout << it << endl;
    }
}
int main(int argc, char *argv[])
{

    vector<int> v = {-1, -100, 3, 99};
    rotate(v, 2);
    return 0;
}