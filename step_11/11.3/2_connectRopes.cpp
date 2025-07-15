#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        //build a mean heap
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        int ans=0;
        //pop two ropes from mean heap and join them
        while(pq.size()>1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            ans+=(t1+t2);
            pq.push(t1+t2);
        }
        return ans;
    }
};