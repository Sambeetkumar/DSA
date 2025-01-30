#include <iostream>
using namespace std;
//https://leetcode.com/problems/delete-node-in-a-linked-list/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 void deleteNode(ListNode* node) {
        /*as we are only provided access to the node which will get deleted, so we can't
        access nodes prior to it.so we can't just rearrange the ll by pointing prev node of 
        target node to the next node of target node*/
        
        /*we will move values of the next node to current node, starting from target node to 
        second last node, then we will simply remove the last node by pointing second last
        node to null ptr*/
        ListNode *temp = node;
        while(temp->next->next != nullptr)
        {
            temp->val = temp->next->val;
            temp = temp->next;
        }
        temp->val=temp->next->val;
        temp->next=nullptr;
}