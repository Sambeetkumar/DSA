#include <bits/stdc++.h>
using namespace std;
void targetSum(vector<int> arr, int sum, int i, int &cnt, int target)
{
    /*when we reach the end of the array, then check if sum == target or not*/
    if (i == arr.size())
    {
        if (sum == target)
            cnt++;

        return;
    }
//calculating subsequence excluding el at index i
    targetSum(arr, sum, i + 1, cnt, target);
//calculating subsequence including el at index i
    sum += arr[i];
    targetSum(arr, sum, i + 1, cnt, target);
}
int perfectSum(vector<int> &arr, int target)
{
    // code here
    int cnt = 0;
    int sum = 0;
    targetSum(arr, sum, 0, cnt, target);
    return cnt;
}
int main(int argc, char *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << perfectSum(arr, 6);

    return 0;
}