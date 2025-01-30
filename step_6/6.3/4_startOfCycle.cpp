#include <bits/stdc++.h>
// link - https://leetcode.com/problems/linked-list-cycle-ii/
//Tortoise-Hare algorithm
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *detectCycle(ListNode *head)
{
    /*manual check for size 0,1 and 2*/
    if (head == NULL)
        return nullptr;
    if (head->next == NULL)
        return nullptr;
    if (head->next->next == NULL)
        return nullptr;
    /*apply tortoise hare algorithm, if at any point head points to null or last node
    then our iteration have come to an end(no loop).*/
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            /*if at any point slow colllides with fast, move fast to head,
            then move both slow and fast by pos 1 untill they collide again.
            now slow and fast points to node from where cycle begins*/
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}