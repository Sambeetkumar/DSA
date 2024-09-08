#include <iostream>
#include <vector>
using namespace std;
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*function to find first occurrence of the target.
if element is not present return -1*/
int findStart(vector<int> &nums, int target)
{
  int low = 0, high = nums.size() - 1, start = -1;
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

/*function to find last occurrence of the target.
if element is not present return -1*/
int findEnd(vector<int> &nums, int target)
{
  int low = 0, high = nums.size() - 1, end = -1;
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

vector<int> searchRange(vector<int> &nums, int target)
{

  int start = findStart(nums, target);
  int end = findEnd(nums, target);
  return {start, end};
}

int main(int argc, char *argv[])
{
  vector<int> v = {5, 7, 7, 8, 8, 10};
  cout << searchRange(v, 8).at(0) << endl;
  cout << searchRange(v, 8).at(1) << endl;

  return 0;
}