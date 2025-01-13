#include <bits/stdc++.h>
using namespace std;
// brute force time complexity O(m+n)
//  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//  {
//      int m = nums1.size();
//      int n = nums2.size();
//      int count = 0;
//      int ind1 = (m + n) / 2;
//      int ind2 = ind1 - 1;
//      int ind1el = -1, ind2el = -1;
//      double median = 0;
//      int i = 0, j = 0;
//      while (i < m && j < n)
//      {
//          if (ind1el != -1 && ind2el != -1)
//          break;
//          cout << count << endl;
//          if (nums1[i] < nums2[j])
//          {
//              if (count == ind1)
//                  ind1el = nums1[i];
//              if (count == ind2)
//                  ind2el = nums1[i];
//              count++;
//              i++;
//          }
//          else
//          {
//              if (count == ind1)
//                  ind1el = nums2[j];
//              if (count == ind2)
//                  ind2el = nums2[j];
//              count++;
//              j++;
//          }
//      }
//      while (j < n)
//      {
//          if (ind1el != -1 && ind2el != -1)
//          break;
//          cout << count << endl;
//          if (count == ind1)
//              ind1el = nums2[j];
//          if (count == ind2)
//              ind2el = nums2[j];
//          count++;
//          j++;
//      }

//     while (i < m)
//     {
//         if (ind1el != -1 && ind2el != -1)
//         break;
//         cout << count << endl;
//         if (count == ind1)
//             ind1el = nums1[i];
//         if (count == ind2)
//             ind2el = nums1[i];
//         count++;
//         i++;
//     }
//     if ((m + n) % 2 == 0)
//     {
//         median = (ind1el + ind2el) / 2.0;
//     }
//     else
//     {
//         median = ind1el;
//     }
//     return median;
// }

// optimal approach

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
    int n = (n1 + n2 + 1) / 2;
    int s = 0, e = n1;
    while (s <= e)
    {
        int mid1 = (s + e) / 2;
        int mid2 = n - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
                return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
            else
                return max(l1, l2);
        }
        else if (l1 > r2)
        {
            e = mid1 - 1;

        }
        else
        {
            s = mid1 + 1;
        }
    }

    return 0;
}
int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,2,5,7};
    vector<int> nums2 = {3,4,10};
    cout << findMedianSortedArrays(nums1, nums2);

    return 0;
}