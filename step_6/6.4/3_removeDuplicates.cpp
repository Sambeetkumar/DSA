#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
Node *removeDuplicates(struct Node *head)
{
    // Your code here
    if (head->next == nullptr)
        return head;
    Node *temp = head;
    Node *ptr = head->next;
    while (ptr != nullptr)
    {
        if (ptr->data != temp->data)
        {
            temp->next = ptr;
            ptr->prev = temp;
            temp = ptr;
        }
        ptr = ptr->next;
    }
    temp->next = nullptr;
    return head;
}