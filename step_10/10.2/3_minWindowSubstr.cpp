#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        //store the freq of chars in t
        unordered_map<char, int> tMap;
        for (auto c : t) {
            tMap[c]++;
        }
        int startingInd=-1;
        int len = INT_MAX;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {
            if (tMap[s[j]] > 0) {
                //we encountered a char present in t
                cnt++;
            }
            tMap[s[j]]--;
            while(cnt == t.size()) {//we got a substring that contains t
                int tempLen = j - i + 1;
                if (tempLen < len) {
                    len = tempLen;
                    startingInd=i;
                }
                //we will compute the length and try to shrink it down
                tMap[s[i]]++;
                if(tMap[s[i]]>0){
                    //one char got removed from our window
                    cnt--;
                }
                i++;
            }
            //after maximum possible shrinking we will expand again
            j++;
        }
        return startingInd==-1?"":s.substr(startingInd,len);
    }
};