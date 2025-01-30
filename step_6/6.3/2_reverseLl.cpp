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
ListNode *reverseList(ListNode *head)
{
    //if ll is of length 0 or length 1, then return as it is
    if (head == NULL || head->next == NULL)
        return head;

    /*reversing a ll using three consecutive pointers respectivel temp,p and n*/
    ListNode *p = head;
    ListNode *temp = nullptr;
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