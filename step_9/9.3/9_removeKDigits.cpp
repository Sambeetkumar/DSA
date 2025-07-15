#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
       int n = num.size();
       string ans;
       //if we can remove the entire string
       if(num.size()==k) return "0";
       stack<char> st;
       for(int i=0; i<n; i++)
       {
        //starting from begining if current el is smaller than st.top(), then pop
        //if we run out of k at any point then don,t pop();
          while(!st.empty() && k>0 && st.top()>num[i])
          {
             st.pop();
             k--;
          }
        /*if we are about push '0', when stack is empty, then don't push it as it will be 
        leading zero*/
          if(!st.empty() || num[i]!='0')
          st.push(num[i]);
       }
       //if any k is left pop the stack k times
       while(!st.empty() && k--) st.pop();

       //if after all stack is empty return "0"
       if(st.empty()) return "0";
       //retrieve the ans string from stack and return ans
       while(!st.empty())
       {
          ans.push_back(st.top());
          st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};