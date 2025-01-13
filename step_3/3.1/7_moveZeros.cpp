#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i<n; i++)
    {
        if(nums[i]!=0)
        {
            if(i!=j)
            {
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
    for(auto it:nums)
    {
        cout << it << endl;
    }
}
int main(int argc, char *argv[])
{

    vector<int> v = {0, 1, 0, 2, 3,0};
    moveZeroes(v);
    return 0;
}