#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

public:
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int val, Node *next1, Node *prev1)
    {
        this->val = val;
        this->next = next1;
        this->prev = prev1;
    }
};

Node *convertToDll(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *prev = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *prev = temp->prev;
    prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    return head;
}

Node *deleteAtkthPos(Node *head, int pos)
{
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
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = ptr;
    temp->next = nullptr;
    temp->prev = nullptr;
    free(temp);

    return head;
}
int main(int argc, char *argv[])
{
    vector<int> v = {2, 1, 4, 3, 6, 9, 5};
    Node *head = convertToDll(v);
    printList(head);
    // cout << "\nafter deleting head" << endl;
    // head = deleteHead(head);
    // printList(head);
    // cout << "\nafter deleting tail" << endl;
    // head = deleteTail(head);
    // printList(head);
    cout << "\ndeleteing node at pos 7" << endl;
    head = deleteAtkthPos(head, 7);
    printList(head);
    return 0;
}