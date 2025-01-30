#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
        return head;
        //calculating length of list
        int cnt=1;
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            cnt++;
            temp=temp->next;
        }
        /*caculating the effective rotation and no of movement after which
        new head will be found*/
        k = k%cnt;
        if(k==0) return head;//if k is 0, return head as it is
        int movement = cnt-k-1;
        ListNode* ptr=head;
        while(movement--)
        {
            ptr = ptr->next;
        }
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;
        temp->next = head;//pointing the next of last node to old head

        return newHead;
    }