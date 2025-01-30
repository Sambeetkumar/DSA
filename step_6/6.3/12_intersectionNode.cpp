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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    /*when length of both lists are equal this algo will end where first commin address id found*/
    /*when any one of the list has greater len than other, then first is places temp1 and temp2
    at equal level then starts search for common address*/
    while (temp1 != temp2)
    {
        temp1 = temp1 ? temp1->next : headB;
        temp2 = temp2 ? temp2->next : headA;
    }
    return temp1;
}