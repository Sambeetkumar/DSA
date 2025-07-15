#include <bits/stdc++.h>
using namespace std;
class Solution {
    int modu = 1e9+7;
public:
    int modAdd(long long a, long long b){
        return ((a%modu)+(b%modu))%modu;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n,n-1);
        vector<int> b(n,0);
        stack<int> st1;
        stack<int> st2;
        /*if we consider arr[i] as min of subarray, then how much can we expand in
        forward direction*/
        for(int i=0; i<n; i++){
            while(!st1.empty() && arr[i]<arr[st1.top()]){
                f[st1.top()]=i-1;
                st1.pop();
            }
            st1.push(i);
        }
        /*if we consider a[i] as min of subarray, then how much can we expand in
        backward direction*/
        /*but there is a catch. consider [71,55,82,55] .If we try to expand 55 at index
        1 in forward direction it will extend till index 3 and 55 at index 3 will
        extend backward till index 1, so the subarray [55,82,55] will be considered
        twice, so to avoid that in forward/backward expansion pop when you encounter
        a smaller or equal element*/
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && arr[i]<=arr[st2.top()]){
                b[st2.top()]=i+1;
                st2.pop();
            }
            st2.push(i);
        }
        //calculate total answer
        long long ans=0;
        for(int i=0; i<n; i++){
            long long currSum = (long long)(f[i]-i+1)*(i-b[i]+1)*arr[i];
            ans = modAdd(ans,currSum);
        }
        return ans;
    }
};