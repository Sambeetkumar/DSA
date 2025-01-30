#include <iostream>
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
Node *segregate(Node *head)
{

    // Add code here
    if (head->next == nullptr)
        return head;
    /*creating three separate lists for 0s, 1s and 2s*/
    Node *zeroHead = new Node(-1), *zero = zeroHead;
    Node *oneHead = new Node(-1), *one = oneHead;
    Node *twoHead = new Node(-1), *two = twoHead;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    /*-connect end of 0s list to the start of 1s head, if there are no 1s connect it to 
    start of 2s list
    -connect end of 1s list to start of 2s list
    -connect end of 2s list to nullptr*/
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    free(oneHead);
    free(twoHead);

    return zeroHead->next;
}