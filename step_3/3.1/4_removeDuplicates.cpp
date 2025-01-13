#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int j = 0;
    int n = nums.size();
    for (int i=1; i<n; i++)
    {
        if(nums[i]!=nums[i-1])
        {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 1,1,1, 2, 2, 3, 4, 5, 5};
    cout<<removeDuplicates(v);

    return 0;
}