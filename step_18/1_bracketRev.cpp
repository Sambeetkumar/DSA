#include <bits/stdc++.h>
using namespace std;
//leetcode link - https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        int minCnt=0;
        for(char ch:s) {
           if(ch==']') {
             cnt--;
             minCnt = min(minCnt,cnt);
           }
           else {
             cnt++;
           }
        }
        return ceil(abs(minCnt)/2.0);
    }
};