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
// function to merge to sorted lists
ListNode *merge(ListNode *A, ListNode *B)
{
    // take a dummy node
    ListNode *dummy = new ListNode(-1);
    ListNode *left = A;
    ListNode *right = B;
    ListNode *temp = dummy; // point temp to the dummy
    while (left != nullptr && right != nullptr)
    {
        // point temp to node with smaller value
        if (left->val <= right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        // move temp to the next node
        temp = temp->next;
    }
    // if any node of left list or right list left after comparison
    if (left != nullptr)
    {
        temp->next = left;
    }
    else
    {
        temp->next = right;
    }
    // return the list by skipping the dummy node
    return dummy->next;
}
ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *sortList(ListNode *head)
{
    // if there is 0 or 1 node only, then no need to sort
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // obtain the middle using totoise hare method
    ListNode *middle = findMiddle(head);
    ListNode *left = head;
    ListNode *right = middle->next;
    middle->next = nullptr;
    // apply sort to the left list and right list individually
    left = sortList(left);
    right = sortList(right);
    // merge the sorted lists
    return merge(left, right);
}