#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    //map to store element with its index of nums2
    unordered_map<int, int> mp;
    stack<int> st;//monotonic stack(top->bottom-increasing)
    /*vector to store next greater element for each el of nums2 
    in their corresponding index*/
    vector<int> ans(n2, 0);
    for (int i = n2 - 1; i >= 0; i--)
    {
        mp[nums2[i]] = i;
        /*when an el comes pop all the elements that are smaller than the el
        encountered as they will be of no use*/
        while (!st.empty() && st.top() < nums2[i])
        {
            st.pop();
        }
        /*if the stack becomes empty, then there is no nextGreater el for the el encountered*/
        if (st.empty())
            ans[i] = -1;
        else
        //otherwise the top el is the nextGreater el
            ans[i] = st.top();
        st.push(nums2[i]);
    }
    //find where the nums1 el lies in nums2 and his corresposning nextGreater element
    for (int i = 0; i < n1; i++)
    {
        int temp = mp[nums1[i]];
        nums1[i] = ans[temp];
    }
    return nums1;
}