#include <bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr)
{
    // Code Here
    int l1 = arr[0];
    int l2 = -1;
    for (auto it : arr)
    {
        if (it > l1)
        {
            l2 = l1;
            l1 = it;
        }
        else if (it > l2 && it != l1)
            l2 = it;
    }

    return l2;
}
int main(int argc, char *argv[])
{
    vector<int> v = {23, 10, 90, 44, 4};
    cout << getSecondLargest(v);

    return 0;
}