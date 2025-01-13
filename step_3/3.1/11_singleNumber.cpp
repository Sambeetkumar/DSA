#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {

    unordered_map<int, int> m;
    if(nums.size()==1)
        return nums[0];
    
    for(auto it:nums)
    {
        m[it]++;
    }
    
    for(auto it:nums)
    {
        if(m[it]==1)
            return it;
    }
    return 0;
}
int main(int argc, char* argv[]) {
    vector<int> v = {4,4, 2, 1, 2};
    cout << singleNumber(v);

    return 0;
}