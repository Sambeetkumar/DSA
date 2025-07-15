#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//we will try assign a cookie of size k to the child with greed g where k is either equal
//to g or just greater than g
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1=g.size(),n2=s.size();
        int i=0,j=0;
        int ans=0;
        while(i<n1 && j<n2)
        {
            //whn both we can assign assign it and move ahead
            if(g[i]<=s[j])
            {
                ans++;
                i++;
                j++;
            }
            //when we can't just move j ahead, bcoz previous cookie sizes are of no use
            else
            {
                j++;
            }
        }
        return ans;
    }
};