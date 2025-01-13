#include <bits/stdc++.h>
using namespace std;
 bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return false;
    //take a freq array of length 26 to store the freq of appearing characters
       int freq[26];
       //updating freq
       for(int i=0; i<s.size(); i++)
       {
         freq[s[i]-'a']++;
       }
       //decrease the freq as a char appears in string t
       for(int i=0; i<t.size(); i++)
       {
         freq[t[i]-'a']--;
       }
       //if any of the char has a freq non-zero after decrement, then return false
       for(int i=0; i<26; i++)
       {
         if(freq[i]!=0) return false;
       }
       
        return true;
        
    }
int main(int argc, char* argv[]) {

    cout << isAnagram("abc", "cab");
    return 0;
}