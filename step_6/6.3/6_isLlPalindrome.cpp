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
/*funtion to reverse linked list from given node*/
ListNode *reversell(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = nullptr;
    ListNode *p = head;
    ListNode *n = head->next;
    while (n != nullptr)
    {
        p->next = temp;
        temp = p;
        p = n;
        n = n->next;
    }
    p->next = temp;
    return p;
}
bool isPalindrome(ListNode *head)
{
    /*using tortoise hare algo, find the mid node or first mid node for odd length or even
    length ll respectively*/
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    /*first point to the head of the linked list, second point to the head of the half reversed
    linked list, ultimately tail of the original linked list*/
    ListNode *first = head;
    ListNode *second = reversell(slow->next);
    ListNode *temp = second;
    /*now we can simply check for palindrome, just using two pointer approach*/
    while (second != nullptr)
    {
        if (first->val != second->val)
        {
            reversell(temp);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    //reverse again to make the original linked list
    reversell(temp);
    return true;
}