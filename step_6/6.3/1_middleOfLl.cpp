#include <iostream>
using namespace std;
//https://leetcode.com/problems/middle-of-the-linked-list/
//Tortoise-Hare algorithm
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;//slow pointer which moves by 1 pos
    ListNode *fast = head;//fast pointer which moves by 2 pos

    /*for even length loop will end when fast points to null and for odd length fast will
    point to the last node*/
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}