#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
       //we will handle negative power at the end 
       long long nn = abs((long long)n);
       double ans = 1;
       while(nn>0){
         //if power is odd take one power out to make it even
         //as we are taking one power out so x will be multiplied in ans
         if(nn&1){
            nn = nn-1;
            ans = ans*x;
         }
         //if power is even reduce power to half
         //as power reduces to half,x will be squared
         else{
            nn = nn/2;
            x = x*x;
         }
       }
       return n<0?1/ans:ans; 
    }
};