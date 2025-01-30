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
int getCount(struct Node* head) {
        int cnt=0;
        Node *temp = head;
        while(temp!=nullptr)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
int main(int argc, char* argv[]) {
    vector<int> v = {1, 2, 3, 4, 5};

    Node *head = convertToLL(v);
    cout << getCount(head);
    return 0;
}