#include <bits/stdc++.h>
using namespace std;

int kthElement(int k, vector<int> &nums1, vector<int> &nums2)
{
    // code here
    int m = nums1.size();
    int n = nums2.size();
    if (m > n)
        return kthElement(k, nums2, nums1);

    int s = max(0, k - n), e = min(m, k);
    while (s <= e)
    {
        int mid1 = s + (e - s) / 2;
        int mid2 = k - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (mid1 < m)
            r1 = nums1[mid1];
        if (mid2 < n)
            r2 = nums2[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            e = mid1 - 1;
        else
            s = mid1 + 1;
    }

    return 0;
}
int main(int argc, char *argv[])
{

    return 0;
}