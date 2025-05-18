#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr
        int cnt = 0;
        // storing elements in the temporary array in a sorted manner//
        // calculating ans - logic copy mai explain kia hua h
        int i = left, j = right;
        while (i <= mid)
        {
            while (j <= high && ceil(double(arr[i]) / 2) > arr[j])
            {
                j++;
            }
            cnt += (j - right);
            i++;
        }
        // normal merging to sorted parts
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int ans = 0;
        if (low >= high)
            return ans;
        int mid = (low + high) / 2;
        ans += mergeSort(arr, low, mid);      // left half
        ans += mergeSort(arr, mid + 1, high); // right half
        ans += merge(arr, low, mid, high);    // merging sorted halves
        return ans;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> arr = {2, 4, 3, 5, 1};
    Solution obj;
    cout << obj.reversePairs(arr);
    return 0;
}