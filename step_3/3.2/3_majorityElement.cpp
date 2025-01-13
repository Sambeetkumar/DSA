#include <bits/stdc++.h>
using namespace std;
//Moore's voting algorithm
int majorityElement(vector<int> &nums)
{
  int n = nums.size();
  int cnt = 0;
  int el;
  /*idea behind voting algorithm is el which appears more than n/2 times can 
  never get cancelled if we compare its freq to the sum of freq of rest elements*/
  for (int i = 0; i < nums.size(); i++)
  {
    if (cnt == 0)
    {
      //choose el pointed by i and set cnt to one
      el = nums[i];
      cnt = 1;
    }
    else if (nums[i] == el)
    {
      //increase cnt as vote is in favour of el
      cnt++;
    }
    else
    {
      //decrease cnt as vote is not in the favour of el
      cnt--;
    }
  }
  cout << "el = " << el << endl;
  //manually checking the freq of el
  int cnt2 = 0;
  for (auto it : nums)
  {
    if (it == el)
      cnt2++;
  }
  //if it is greater than n/2 then it is the majority el
  if (cnt2>(n/2))
  return el;
  else//else majority el doesn't exist
  return -1;
}
int main(int argc, char *argv[])
{
  vector<int> v = {2, 2, 1, 1, 1, 2, 2,1};
  cout << majorityElement(v);

  return 0;
}