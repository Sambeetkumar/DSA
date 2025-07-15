#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int> freq;
        int n = arr.size();
        int i=0,j=0;
        int maxLen=0;
        while(j<n){
            freq[arr[j]]++;
            //when we get a maxLen, we will never shrink our window below that length, instead
            //of that we will try sliding it by one position inorder to find a valid subarray ahead.
            //then we will try to expand our window again
            if(freq.size()>2){
                freq[arr[i]]--;
                if(freq[arr[i]]==0){
                    freq.erase(arr[i]);
                }
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
//O(2*n) complexity
// class Solution {
//   public:
//     int totalElements(vector<int> &arr) {
//         // code here
//         unordered_map<int,int> freq;
//         int n = arr.size();
//         int i=0,j=0;
//         int maxLen=0;
//         while(j<n){
//             freq[arr[j]]++;
//             while(freq.size()>2){
//                 freq[arr[i]]--;
//                 if(freq[arr[i]]==0){
//                     freq.erase(arr[i]);
//                 }
//                 i++;
//             }
//             maxLen = max(maxLen,j-i+1);
//             j++;
//         }
//         return maxLen;
//     }
// };