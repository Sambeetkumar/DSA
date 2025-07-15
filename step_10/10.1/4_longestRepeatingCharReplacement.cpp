#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//Time complexity - O(n)
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size();
        int len = 0;
        int i = 0, j = 0;
        int maxFreq = 0;
        while (j < n) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            //to optimise, when we get a maxlen we will never shrink our window below that len
            //we will try sliding that window to get a valid subarray, then we will try expanding it
            if((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                //we don't need to re-calaculate the max freq again, because it will always decrease
                //decreased freq will never satisfy the condition as our window will never shrink
                i++;
            }
            if ((j - i + 1) - maxFreq <= k) {
                len = max(len, j - i + 1);
            }
            j++;
        }
        return len;
    }
};
//O(2*N*26) time complexity
// int characterReplacement(string s, int k) {
//     vector<int> freq(26, 0);
//     int n = s.size();
//     int len = 0;
//     int i = 0, j = 0;
//     int maxFreq = 0;
//     while (j < n) {
//         freq[s[j] - 'A']++;
//         maxFreq = max(maxFreq, freq[s[j] - 'A']);
//         //if the no required conversions exceed k, shrink the window
//         while ((j - i + 1) - maxFreq > k) {
//             freq[s[i] - 'A']--;
//             maxFreq = *max_element(freq.begin(), freq.end());
//             i++;
//         }
//         //update the len when number of conversions are in the range k
//         if ((j - i + 1) - maxFreq <= k) {
//             len = max(len, j - i + 1);
//         }
//         j++;
//     }
//     return len;
// }