#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> ans(n,0);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && A[i]<=st.top())
        st.pop();
        
        ans[i]=st.empty()?-1:st.top();
        st.push(A[i]);
    }
    return ans;
}