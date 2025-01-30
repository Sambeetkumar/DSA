#include <bits/stdc++.h>
// link - https://leetcode.com/problems/linked-list-cycle/
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool hasCycle(ListNode *head)
{
    /*manual check for size 0,1 and 2*/
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return false;
    if (head->next->next == NULL)
        return false;
    /*apply tortoise hare algorithm, if at any point head points to null or last node
    then our iteration have come to an end(no loop). if at any point slow fast collide
    then we are in a loop, so return true*/
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}