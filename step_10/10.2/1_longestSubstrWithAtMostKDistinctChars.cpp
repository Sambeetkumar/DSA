#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    // Time complexity O(N)
    unordered_map<char,int> freq;
    int n = str.size();
    int len=0;
    int i=0,j=0;
    while(j<n){
        freq[str[j]]++;
        //as we have got a max len substr, we will try to slide our window, never shrink below that
        if(freq.size()>k){
            freq[str[i]]--;
            if(freq[str[i]]==0){
                freq.erase(str[i]);
            }
            i++;
        }
        //expand as far as possible
        if(freq.size()<=k){
            len = max(len,j-i+1);
        }
        j++;
    }
    return len;
}