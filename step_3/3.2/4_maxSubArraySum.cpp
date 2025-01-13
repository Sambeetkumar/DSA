#include <bits/stdc++.h>
using namespace std;
//Kadane's Algorithm
int maxSubArray(vector<int>& nums) {
  int maxi = INT_MIN;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    maxi = max(sum, maxi);
    /*if sum of a sub array goes negative, then it will reduce the entire sum if we expand
    the sub array, so set sum to 0 i.e. don't consider that sub array and start again from
    the end of this sub array.*/
    if(sum<0)
    sum = 0;
  }
  //returning maximum sum
  return maxi;
    
  }
int main(int argc, char* argv[]) {
  vector<int> v = {5,4,-1,7,8};
  cout << maxSubArray(v);

  return 0;
}