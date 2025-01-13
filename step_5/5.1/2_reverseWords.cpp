#include <bits/stdc++.h>
// https://leetcode.com/problems/reverse-words-in-a-string/
using namespace std;
string reverseWords(string s) {
       int i=0,l=0,r=0;
       int n = s.size();
       reverse(s.begin(),s.end());//initially reverse the entire sentence
       while(i<n)
       {
          while(i<n && s[i]!=' ')
          {//when we encouter our first alphabet assign it to r and move r forward
             s[r]=s[i];
             i++;
             r++;
          }
          /*when we encounter a space above loop breaks and we have word between l to r-1*/
          if(l<r)
          {
            /*reversing indivisual word and adding a space after it, then moving l to the
            pos of r as we have successfuly placed a word in its pos*/
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
          }
          i++;
       } 
       /*return sub string of s from index 0 to r-1 as r is pointing next to the space after
       last word*/
       return s.substr(0,r-1);
    }
int main(int argc, char* argv[]) {
    string str = "  I am a   boy   ";
    string ans = reverseWords(str);
    cout << ans;

    return 0;
}