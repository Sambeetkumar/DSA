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
ListNode *deleteMiddle(ListNode *head)
{
    // if there is only one node simply return null
    if (head->next == nullptr)
        return nullptr;
    // finding the middle node
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    /*slow points to the node to be deleted. move temp node to prev node os slow and
    point next of temp to next of slow(skip slow)*/
    ListNode *temp = head;
    while (temp->next != slow)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}