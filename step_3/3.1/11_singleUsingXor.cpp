#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0; i<nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
int main(int argc, char* argv[]) {
  vector<int> v = {4,4, 2, 1, 2};
  cout << singleNumber(v);
  
  return 0;
}