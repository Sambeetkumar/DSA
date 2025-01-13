#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s) {
    /*vector to hash freq with its char, we will take vector of type pair<int,char>
    and it will be of size ascii(z)+1 as each index corresponds to its char(index)*/
    vector<pair<int,char>>hash('z'+1,{0,0});
     for(char c:s)
     {
         /*when we encounter a char we will go to the index corresponding to its ascii value
         and increase the freq by 1*/
         hash[c] = {hash[c].first + 1, c};
     }
     //now sort it in the increasing order of freq
     sort(hash.begin(),hash.end());
     string res="";
     for(auto it:hash)
     {
        /*add the char to the resultant string by the number time it appears in original
        string*/
        res=string(it.first,it.second)+res;
        /*string(int a, char b) it returns a string in which char b appears a time, e.g. 
        string(5,c) = "ccccc"*/
     }
     return res;
    }
int main(int argc, char* argv[]) {
  
  
  return 0;
}