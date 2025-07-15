#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //ans = sum of subarray maximums - sum of subarray minimums
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        //finding the sum of sub array minimums
        stack<int> st1;
        stack<int> st2;
        vector<int> l1(n,0);
        vector<int> r1(n,n-1);
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[i]<nums[st1.top()]){
                r1[st1.top()]=i-1;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[i]<=nums[st2.top()]){
                l1[st2.top()]=i+1;
                st2.pop();
            }
            st2.push(i);
        }
        long long subMin=0;
        for(int i=0; i<n; i++){
            subMin += (long long)(r1[i]-i+1)*(i-l1[i]+1)*nums[i];
        }
        //finding the sum of subarray maximums
        stack<int> st3;
        stack<int> st4;
        vector<int> l2(n,0);
        vector<int> r2(n,n-1);
        for(int i=0; i<n; i++){
            while(!st3.empty() && nums[i]>nums[st3.top()]){
                r2[st3.top()]=i-1;
                st3.pop();
            }
            st3.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!st4.empty() && nums[i]>=nums[st4.top()]){
                l2[st4.top()]=i+1;
                st4.pop();
            }
            st4.push(i);
        }
        long long subMax=0;
        for(int i=0; i<n; i++){
            subMax += (long long)(r2[i]-i+1)*(i-l2[i]+1)*nums[i];
        }
        //return the difference
        return subMax-subMin;
    }
};