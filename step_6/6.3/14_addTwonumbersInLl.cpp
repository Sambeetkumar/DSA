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
//function to insert a node at the end
ListNode *insertAtEnd(ListNode *head, int val)
{
    ListNode *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    ListNode *newNode = new ListNode(val);
    temp->next = newNode;
    return head;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *ans = new ListNode(-1);
    int carry = 0;
    //performing addition, adding the digit to the ans as a new node and generating carry
    while (temp1 != nullptr && temp2 != nullptr)
    {
        int sum = temp1->val + temp2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans = insertAtEnd(ans, digit);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    /*when one number is smaller, after the smaller number ends we need to perform
    addition of carry with the other one*/
    while (temp1 != nullptr)
    {
        int sum = temp1->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans = insertAtEnd(ans, digit);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        int sum = temp2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans = insertAtEnd(ans, digit);
        temp2 = temp2->next;
    }
    //if at the end any carry remains add it as a new node
    if (carry != 0)
        ans = insertAtEnd(ans, carry);
    //return by skipping the first dummy node.
    return ans->next;
}