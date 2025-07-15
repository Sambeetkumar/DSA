#include <bits/stdc++.h>
using namespace std;
//maintain a mean heap of {el,elIndex} the cal ans by popping in increasing order
class Compare{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        if(a.first>b.first){
            return true;
        }
        else if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return false;
        }
    }
};
class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> ans(N);
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i=0; i<N; i++){
            pq.push({arr[i],i});
        }
        int cnt=1;
        while(!pq.empty()){
            int topEl=pq.top().first;
            int topInd = pq.top().second;
            pq.pop();
            ans[topInd]=cnt;
            while(!pq.empty() && pq.top().first==topEl){
                ans[pq.top().second]=cnt;
                pq.pop();
            }
            cnt++;
        }
        return ans;
    }
};
