#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;//we will store indices in deque
        int n = nums.size();
        int i=0,j=0;
        while(j<n)
        {
            /*when a bigger elements comes in window remove all smaller elements form the back
            bcause they are of no use*/
            while(!dq.empty() && nums[dq.back()]<=nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);
            if(j-i+1==k)
            {
                //when window size hits our ans for window will be at the front
                ans.push_back(nums[dq.front()]);
                //before moving i, check if it points to the larger element or not
                if(i==dq.front())
                dq.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};