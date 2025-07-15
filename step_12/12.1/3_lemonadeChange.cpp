#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//try giving change to customer with whateven coins we have (process each greedily)
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(auto it:bills){
            mp[it]++;
            if(it==10){
                if(mp[5]==0){
                    return false;
                }
                mp[5]--;
            }
            if(it==20){
                if(mp[5]==0 || (mp[10]==0 && mp[5]<3)){
                    return false;
                }
                if(mp[10]==0){
                    mp[5]-=3;
                }
                else{
                    mp[10]--;
                    mp[5]--;
                }
            }
        }
        return true;
    }
};