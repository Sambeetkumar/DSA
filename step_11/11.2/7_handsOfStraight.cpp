#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        //if n is not divisible by groupSize then return false
        if (n % groupSize != 0)
            return false;
        //we are taking an ordered map bcoz we will pick elements in sorted order
        map<int, int> mp;
        for (int el : hand) {
            mp[el]++;
        }
        //start forming groups from the start of the map
        while (!mp.empty()) {
            int curr = mp.begin()->first;
            //considering curr try forming groups
            for (int i = 0; i < groupSize; i++) {
                //if any required el is not present
                if (mp.find(curr + i) == mp.end()) {
                    return false;
                }
                //remove fully consumed elments from the map
                mp[curr + i]--;
                if (mp[curr + i] == 0) {
                    mp.erase(curr + i);
                }
            }
        }
        return true;
    }
};