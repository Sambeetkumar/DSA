#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
//complexity O(k*logk)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int m = nums1.size();
        int n = nums2.size();
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        //mean heap to store {sum,i,j}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        //keep track of visited pairs {i,j}
        set<pair<int,int>> visited;

        //initial state - start with {0,0}
        pq.push({nums1[0]+nums2[0],0,0});
        visited.insert({0,0});

        while(!pq.empty() && result.size()<k){
            vector<int> top = pq.top();
            int sum = top[0];
            int i= top[1];
            int j= top[2];
            pq.pop();
            //push the minimum to result
            result.push_back({nums1[i],nums2[j]});

            //check for i+1
            if(i+1<m && !visited.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                visited.insert({i+1,j});
            }
            //check for j+1
            if(j+1<n && !visited.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};