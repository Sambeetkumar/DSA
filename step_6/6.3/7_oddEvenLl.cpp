#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *oddEvenList(ListNode *head)
{
    // if length of ll is 0 or 1 return head
    if (head == nullptr || head->next == nullptr)
        return head;
    // connecting all odd nodes together and even nodes together
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    // point the end of odd nodes list to the head of even nodes list
    odd->next = evenHead;
    return head;
}