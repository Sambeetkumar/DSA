#include <bits/stdc++.h>
using namespace std;
//same concept as book allocation problem and split array problem
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int s = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(), 0);

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int sum = 0, count = 1;
        for (int j = 0; j < n; j++)
        {
            if (sum + boards[j] > mid)
            {
                sum = boards[j];
                count++;
            }
            else
            {
                sum += boards[j];
            }
        }
        if (count <= k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return s;
}
int main(int argc, char *argv[])
{
    vector<int> v = {10, 20, 30, 40};
    cout << findLargestMinDistance(v, 2);

    return 0;
}