#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = nullptr;
    Node *p = head;
    Node *n = head->next;
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
Node *addOne(Node *head)
{
    // Your Code here
    // first reverse the given linked list
    Node *temp = reverse(head);
    Node *revHead = temp;
    /*now just perform simple addition, if the digit is less than 9, increase it by 1 and break the loop
    if its 9, make it 0 and carry 1 to next node */
    while (temp->next != nullptr)
    {
        if (temp->data < 9)
        {
            temp->data++;
            break;
        }
        temp->data = 0;
        temp = temp->next;
    }
    /*if the last node digit is less than 9 do the same increase it by 1, if it is
    9 then make it 0 and add another node with value 1 to linked list*/
    if (temp->next == nullptr)
    {
        if (temp->data < 9)
        {
            temp->data++;
        }
        else
        {
            temp->data = 0;
            Node *temp2 = new Node(1);
            temp->next = temp2;
            temp = temp->next;
        }
    }
    //reverse the linked list and return it
    return reverse(revHead);
}