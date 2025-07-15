#include <bits/stdc++.h>
using namespace std;
//solution using lps array - O(n) complexity
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        //stores the length of lps for each index i
        vector<int> lps(n,0);
        int len=0;
        //lps[0] is always 0, start from index 1
        int i=1;
        while(i<n) {
            //if there's a match move len as well as i
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{//if no match move len back to lps[len-1]
                if(len>0) {
                    len = lps[len-1];
                }
                //if len reaches at 0, then no match found for s[i], store lps[i]=0
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,len);
    }
};