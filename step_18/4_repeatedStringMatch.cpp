#include <bits/stdc++.h>
using namespace std;
class Solution {
    //solution using rabin karp algorithm
public:
    int repeatedStringMatch(string a, string b) {
       int m=a.size();
       int n=b.size();
       int base=26;
       int aHash=0;
       int bHash=0;
       int pPow=1;
       int i=0;
       int j=0;
       int modu=101;
       //updating pPow- it will be used while sliding the window
       for(int k=0; k<n-1; k++) {
         pPow = (pPow*base)%modu;
       }
       //calculate hash value of pattern and initial window of text
       for(int k=0;k<n;k++)
       {
           bHash=(bHash*base+b[k])%modu;
           aHash=(aHash*base+a[j%m])%modu;//we are using j%m because we are tarversing in a in cyclic order
           j++;
       }
       //slide the pattern 
       /*if there is matching pattern then start of matching window must lie in [0,m-1]*/
       for(i=0;i<m;i++)
       {
           //check if hash matches
           if(aHash==bHash)
           {
               int k;
               for(k=0;k<n;k++)
               {
                   if(b[k]!=a[(i+k)%m])
                   break;
               }
               if(k==n)
               {
                  //match is found
                  break;
               }
           }
            //updating aHash to slide the window
            aHash=(base*(aHash-a[i]*pPow)+a[j%m])%modu;
            j++;
            if(aHash<0)
            aHash=aHash+modu;
       }
       //if match is found that matching window is [i,j-1]
       return i==m?-1:ceil(j/(double)m);
    }
};