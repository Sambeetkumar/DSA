#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
Node *deleteNode(Node *head, int pos)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return NULL;
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        free(temp);
        return head;
    }
    Node *ptr = head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    Node *p = ptr->prev;
    if (ptr->next != NULL)
    {
        Node *n = ptr->next;
        n->prev = p;
    }
    p->next = ptr->next;
    ptr->next = NULL;
    ptr->prev = NULL;

    return head;
}
