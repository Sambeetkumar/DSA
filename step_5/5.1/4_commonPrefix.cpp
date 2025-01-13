#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
       if(n==1) return strs[0];
       //asign the first string to ans
       string ans = strs[0];
       for(int i=1; i<n; i++)
       {
          int j=0;
          string temp="";
          int n = min(ans.size(),strs[i].size());
          /*comparing ans with the string pointed by i*/ 
          while(j<n && ans[j]==strs[i][j])
          {
            temp+=ans[j];
            j++;
          }
          /*updating ans with the common part*/
          ans=temp;
         
       }
       return ans; 
    }
int main(int argc, char* argv[]) {
    vector < string > v= {"flower", "flow", "flight"};
    string prefix = longestCommonPrefix(v);
    cout << prefix;

    return 0;
}