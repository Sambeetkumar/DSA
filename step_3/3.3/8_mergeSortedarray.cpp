#include <bits/stdc++.h>
// https://leetcode.com/problems/merge-sorted-array/
using namespace std;
// O(mlogm + nlogn) approach
//  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n==0) return;//if nums2 is empty, then return nums1 as it is already

//        /*pointing i to the end non-zero el of nums1
//        pointing j to the start of nums2*/
//        int i=m-1,j=0;
//        while(i>=0 && j<n)
//        { /*if el pointed by i is greater than el pointed by j,then swap because that
//            should be in nums2*/
//          if(nums1[i]>nums2[j])
//          {
//             swap(nums1[i],nums2[j]);
//             i--;
//             j++;
//          }
//          else
//          {
//             /*where nums1[i]<nums2[j], then no swaps needed furter as all elements <=i
//             are samller than all elements >= j, as both are sorted.*/
//             break;
//          }
//        }
//        //sorting both arrays indivisually
//        sort(nums1.begin(),nums1.begin()+m);
//        sort(nums2.begin(),nums2.end());
//        //inserting nums2 in place of zeros at the end of nums1
//        for(int i=0; i<n; i++)
//        {
//           nums1[i+m] = nums2[i];
//        }
//     }

// O(m+n) approach
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
   if (n == 0)
      return;
   // 3 pointer approach
   int i = m - 1, j = n - 1, k = nums1.size() - 1;
   // i points to the largest el of nums1, j points to the largest el in nums2
   /*k points to the end of nums1, from where we will start filling
   compare nums1[i] and nums2[j] place the larger el at k and move pointers
   accordingly*/
   while (i >= 0 && j >= 0)
   {
      if (nums1[i] >= nums2[j])
      {
         nums1[k] = nums1[i];
         i--;
      }
      else
      {
         nums1[k] = nums2[j];
         j--;
      }
      k--;
   }
   /*in some case i may reach 0 before j, that means in nums2 elements from
   index 0 to j are smaller than all el of nums1, place them using pointer k*/
   while (j >= 0)
   {
      nums1[k] = nums2[j];
      j--;
      k--;
   }
}
int main(int argc, char *argv[])
{
   vector<int> v1 = {1, 2, 3, 0, 0, 0};
   vector<int> v2 = {2, 6, 7};
   merge(v1, 3, v2, 3);
   for (auto it : v1)
   {
      cout << it << " ";
   }

   return 0;
}