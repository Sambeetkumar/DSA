#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        //edge case
        if(s=="") return s;
        /*we need to find the longest palindromic prefix, it will remain untouched
        and the rest of the string will br+e reversed appended in the begining to
        make the whole string a palindrome*/
        /*the longest palindromic prefix will also be the suffix of the reversed
        string. so we will use the lps array to find the length of the longest
        palindromic prefix*/
        string rev = s;
        reverse(rev.begin(),rev.end());
        //concat both str and str.rev to build lps array. put a '*' inbetween to
        //stop overlapping of prefix and suffix
        string tot = s+'*'+rev;
        int n = tot.size();
        vector<int> lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(tot[i]==tot[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int addSize = s.size()-lps[n-1];
        //extract the substr from rev that needs to be appended in front of s
        string add = rev.substr(0,addSize);
        return add+s;
    }
};