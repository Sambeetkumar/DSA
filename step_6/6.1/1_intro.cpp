#include <bits/stdc++.h>
using namespace std;
//declaring class node
class Node
{
public:
    int data;
    Node *next;
    //constructor
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};
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
int main(int argc, char *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *temp = convertToLL(arr);
    //printing ll
    while(temp!=nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    return 0;
}