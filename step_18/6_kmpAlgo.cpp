#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void buildLps(string &s,vector<int> &lps){
        int m = s.size();
        int len=0;
        int i=1;
        while(i<m){
            if(s[i]==s[len]){//match
                len++;
                lps[i]=len;
                i++;
            }
            else {//no match
                if(len!=0)
                len = lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int m = pat.size();
        int n = txt.size();
        //create lps array
        //lps[i] the length of longest proper prefix of pat[0...i]
        //which is also a suffix of pat[0...i]
        vector<int> lps(m,0);
        buildLps(pat,lps);
        //now apply kmp
        vector<int> ans;
        int i=0,j=0;
        while(i<n){
            //if it's a match
            if(txt[i]==pat[j]) {
                i++;
                j++;
            }
            //if no match
            else {
                if(j!=0) {
                    j=lps[j-1];
                }
                else{
                   i++; 
                }
            }
            //if after incrementing j reaches at m- pattern is found once
            if(j==m) {
                ans.push_back(i-m);
                j=lps[j-1];
            }
        }
        return ans;
    }
};