#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
Node *deleteAllOccurrences(Node *head, int k)
{
    // Write your code here
    Node *ptr = head;
    while (ptr != nullptr)
    {
        //if ptr lands on the target element
        if (ptr->data == k)
        {
            Node *temp = ptr;
            //if it is the one and only node of the ll
            if (ptr->prev == NULL && ptr->next == NULL)
                return NULL;
            //if it is the starting node of ll
            else if (ptr->prev == NULL)
            {
                head = head->next;
                ptr = ptr->next;
                ptr->prev = nullptr;
                temp->next = nullptr;
            }
            //if it is the end node of the ll
            else if (ptr->next == NULL)
            {
                ptr = ptr->prev;
                ptr->next = NULL;
                temp->prev = nullptr;
                break;
            }
            //if ptr is somewhere in the middle of ll
            else
            {
                ptr = ptr->next;
                temp->prev->next = ptr;
                ptr->prev = temp->prev;
                temp->next = nullptr;
                temp->prev = nullptr;
            }
            free(temp);
        }
        //if ptr doesn't point to the target el simply move ahead
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
}