#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max_cnt = 0, cnt = 0;
    for (auto it : nums)
    {
        if (it == 1)
            cnt++;
        else
        {
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
            }
            cnt = 0;
        }
    }
    if (cnt > max_cnt)
    {
        max_cnt = cnt;
    }
    return max_cnt;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 0, 1, 1, 0, 1};
    cout << findMaxConsecutiveOnes(v);

    return 0;
}