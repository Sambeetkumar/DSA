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
Node *addNode(Node *head, int pos, int data)
{
    // code here
    Node *temp = new Node(data);
    Node *p = head;
    //if pos is 0 handle it
    if (pos == 0)
    {
        temp->next = p;
        p->prev = temp;
        head = temp;
        return head;
    }
    for (int i = 1; i <= pos; i++)
    {
        p = p->next;
    }
    if (p->next != NULL)
    {
        Node *n = p->next;
        temp->next = n;
        n->prev = temp;
    }
    p->next = temp;
    temp->prev = p;

    return head;
}