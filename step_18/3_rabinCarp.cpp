#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
class Solution {
  public:
  /*the idea is to create a hash function and calculate the hash value of the pattern, now
  for each window in text calc hash value, if both th hash values are equal then pattern
  may match so compare the window with pattern. This algo highly reduces the number of comparisons.
  the avg time complexity becomes O(m+n)*/
  /*
    Working of hashing function
    pattern = "abcd"
    hash value = (d*(26^0)%modu + c*(26^1)%modu + b*(26^2)%modu + a*(26^3)%modu)%modu
    base - 26
    modu - any prime number(let's say 101)
  */
    vector<int> search(string pattern, string text) {
       int n=pattern.length();
       int m=text.length();
       int base=26;
       int pHash=0;
       int tHash=0;
       int pPow=1;
       int j;
       int modu=101;
       vector<int>ans;
       //updating pPow i.e. base^(n-1)
       for(int i=0;i<n-1;i++)
       {
           pPow=(pPow*base)%modu;
       }
       //calculate hash value of pattern and initial window of text
       for(int i=0;i<pattern.length();i++)
       {
           pHash=(pHash*base+pattern[i])%modu;
           tHash=(tHash*base+text[i])%modu;
       }
       //slide the pattern 
       for(int i=0;i<=m-n;i++)
       {
           //check if hash matches
           if(pHash==tHash)
           {
               for(j=0;j<n;j++)
               {
                   if(pattern[j]!=text[i+j])
                   break;
               }
               if(j==n)
               {
                    ans.push_back(i+1);
               }
           }
           
          if(i<m-n)
          {
              //updating tHash to slide the window
              tHash=(base*(tHash-text[i]*pPow)+text[i+n])%modu;
              if(tHash<0)
              tHash=tHash+modu;
          }
       }
       return ans;
    }
};