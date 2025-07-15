#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap for end days
        int day = 1;
        int cnt = 0;
        int i = 0;
        int n = events.size();
        
        while (i < n || !pq.empty()) {
            // Add all events that start on the current day
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // Attend the event that ends the earliest
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
            
            day++;
        }
        
        return cnt;
    }
};