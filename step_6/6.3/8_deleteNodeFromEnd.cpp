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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // finding the length of linked list
    ListNode *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    // finding node to be deleted from the start of linked list
    int nodeToDlt = cnt - n + 1;
    // if first node is to deleted simply move head
    if (nodeToDlt == 1)
    {
        head = head->next;
        return head;
    }
    // performing deletion
    temp = head;
    for (int i = 1; i < nodeToDlt - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;

    return head;
}