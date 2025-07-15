#include <bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  //custom comparator
class Compare{
    public:
    bool operator()(pair<ListNode*,int> &a, pair<ListNode*,int> &b){
        if(b.first->val<a.first->val){
            return true;
        }
        else if(a.first->val==b.first->val){
            return b.second<a.second;
        }
        else{
            return false;
        }
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,Compare> pq;
        int n = lists.size();
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        //maintain a intial minheap of nodes in the first col
        for(int i=0; i<n; i++){
            if(lists[i])
            pq.push({lists[i],i});
        }
        while(!pq.empty()){
            //keep popping the node with smallest value and adding it's next node
            pair<ListNode*,int> top = pq.top();
            pq.pop();
            temp->next = top.first;
            if(top.first->next)
            pq.push({top.first->next,top.second});
            temp = temp->next;
            temp->next=NULL;
        }

        return dummy->next;
    }
};