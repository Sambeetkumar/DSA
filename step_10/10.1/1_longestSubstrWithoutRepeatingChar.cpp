#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //map- char with its latest occurrence
        unordered_map<char,int> m;
        int maxLen=0;
        int i=0,j=0;
        int n = s.size();
        while(j<n)
        {
            //when we encounter a char that is already occurred, then we need to move i
            //atleast to its prevInd+1 inorder to make the subarray valid
            if(m.find(s[j])!=m.end() && m[s[j]]>=i)
            {
                i=m[s[j]]+1;
            }
            //then update its latest occurrence
            m[s[j]]=j;
            maxLen = max(maxLen,(j-i+1));
            j++;
        }
        return maxLen;
        
    }
};

//Approach - 2
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         unordered_map<int,int> freq;
//         int maxLen = 0;
//         int i=0,j=0;
//         while(j<n){
//             freq[s[j]]++;
//             //if the subarray is invalid we will slide the current window instead of
//             //shrinking it - basically once we get a maxLen we will never shrink our window
//             //below that size
//             if((j-i+1)>freq.size()){
//                 freq[s[i]]--;
//                 if(freq[s[i]]==0){
//                     freq.erase(s[i]);
//                 }
//                 i++;
//             }
//             //check is the subarray valid
//             if((j-i+1)==freq.size()){
//                 maxLen = max(maxLen,(j-i+1));
//             }
//             j++;
//         }
//         return maxLen;
//     }
//};