#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    stack<int> st;
    for(int i=2*n-1; i>=0; i--)
    {
        //virtually doubling the array and finding the next greater element
        while(!st.empty() && nums[i%n]>=st.top())
        {
            st.pop();
        }
        //update ans only if i in in the range n
        if(i<n)
        {
            ans[i]=st.empty()?-1:st.top();
        }
        st.push(nums[i%n]);
    }
    return ans;
}