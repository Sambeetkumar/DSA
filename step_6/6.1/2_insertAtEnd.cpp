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
Node *insertAtEnd(Node *head, int x)
{
    // if given ll size is zero, then only create one node with given data and return it
    if (head == nullptr)
    {
        Node *head = new Node(x);
        return head;
    }
    /* asign a temp node to head and move it untill it points to the last node, then point
    to the newly created node*/
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *ptr = new Node(x);
    temp->next = ptr;

    return head;
}
Node* convertToLL(vector<int> v)
{
    //assigning initial node to head ptr
    Node *head = new Node(v[0]);
    /*declaring a pointer ptr intially pointing to head, then adding one each time and
    moving ptr one by one in each step*/
    Node *ptr = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        ptr->next = temp;
        ptr = temp;
    }
    return head;
}
void printList(Node* head)
{
    Node *temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}
int main(int argc, char *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    cout << "before insertion\n";
    printList(head);
    head = insertAtEnd(head, 6);
    cout << "\nafter insertion\n";
    printList(head);

    return 0;
}