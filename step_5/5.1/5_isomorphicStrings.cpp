#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1;//mapping from s to t
        unordered_map<char,char> m2;//mapping from t to s
        int n = s.size();
        for(int i=0; i<n; i++)
        {
           if(m1.find(s[i])!=m1.end())
           {
              /*if s[i] is alreday mapped with a char, then check whether is is
              t[i] or not, if not return false*/
              if(m1[s[i]]!=t[i]) return false;
           }
           else
           {
               /*if s[i] is not mapped with any char, then check whether t[i] has any
               preimage or not, if not then map s[i] to t[i] in both maps*/
               if(m2.find(t[i])==m2.end())
               {
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
               }
               else
               //if t[i] already has an pre-image then it can't be mapped with s[i], return false
               return false;
           }
        }
        return true;
    }
int main(int argc, char* argv[]) {
    string s = "abc";
    string t = "adh";
    cout << isIsomorphic(s, t);

    return 0;
}