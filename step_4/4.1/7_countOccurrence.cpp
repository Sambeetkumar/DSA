#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

int findStart(int nums[], int n, int target)
{
  int low = 0, high = n - 1, start = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
      start = mid;
      high = mid - 1;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return start;
}

int findEnd(int nums[], int n, int target)
{
  int low = 0, high = n-1, end = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
      end = mid;
      low = mid + 1;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return end;
}
int count(int arr[], int n, int x) {
	    // code here
        int low = findStart(arr, n, x);
        int high = findEnd(arr, n, x);

        if(low==-1 || high == -1)
        return 0;
        else
        return (high - low) + 1;
    }
int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
   
    cout << count(arr, 7, 4);
}
