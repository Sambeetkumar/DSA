#include <bits/stdc++.h>
using namespace std;
class KthLargest {
    //maintain a mean heap of size k
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int el:nums){
            if(pq.size()<k){
                pq.push(el);
            }
            else{
                if(el>pq.top()){
                    pq.pop();
                    pq.push(el);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<size){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};