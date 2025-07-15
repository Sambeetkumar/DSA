#include <bits/stdc++.h>
using namespace std;
class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store the freq of each element
        unordered_map<int,int> freq;
        for(int i:nums)
        {
            freq[i]++;
        }
        if(freq.size()==nums.size() && nums.size()==k)
        return nums;
        //min heap of {element, frequency} - lesser freq has more priority
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> minPq;
        for(auto it:freq)
        {
            if(minPq.size()<k)
            minPq.push({it.first,it.second});
            else
            {   //if the upcoming el has more freq than top of pq, then pop the top and push
                if(it.second>minPq.top().second)
                {
                    minPq.pop();
                    minPq.push({it.first,it.second});
                }
            }
        }
        //now the min heap contains k most frequent elements with their frequency
        vector<int> ans;
        while(!minPq.empty())
        {
            ans.push_back(minPq.top().first);
            minPq.pop();
        }
        return ans;
    }
};