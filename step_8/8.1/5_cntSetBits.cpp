#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        // Your logic here
        int bits = log2(n)+1;
        int newNum = n+1;
        int s = 2;
        int x = 1;
        int ans=0;
        for(int i=0; i<bits; i++){
            int q = newNum/s;
            int rem = newNum%s;
            ans+= q*x;
            if((rem-(s/2))>0)
            ans+=(rem-(s/2));
            x = x*2;
            s = s*2;
        }
        return ans;
    }
};
