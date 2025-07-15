#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return true;
        bool sign = true;
        if((long)dividend*divisor<0) sign = false;
        long n = abs(long(dividend));
        long d = abs(long(divisor));
        long quotient =0;

        while(n>=d)
        {
            int cnt=0;
            while(n>= d<<(cnt+1))
            {
                cnt++;
            }
            quotient+=(1<<cnt);
            n = n-(d<<(cnt));
        }

        if(quotient == (1<<31))
        {
            if(sign)
            return INT_MAX;
            else
            return INT_MIN;
        }

        return sign?quotient:-quotient;
    }
};