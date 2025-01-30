#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *A, Node *B)
{
    /*calling merge function recursively until A reaches the last node and B becomes null
    when B becomes null return A, as there result of merging will be A only*/
    if (B == nullptr)
        return A;
    /*we are actually merging two sublists recursively in a sorted manner from the end
    the given list*/
    B = merge(A->next, B->next);
    // merging two lists in sorted order
    Node *dummy = new Node(-1);
    Node *ptr = dummy;
    Node *temp1 = A;
    Node *temp2 = B;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data >= temp2->data)
        {
            ptr->bottom = temp2;
            temp2 = temp2->bottom;
        }
        else
        {
            ptr->bottom = temp1;
            temp1 = temp1->bottom;
        }
        ptr = ptr->bottom;
    }
    if (temp1 != nullptr)
    {
        ptr->bottom = temp1;
    }
    else
    {
        ptr->bottom = temp2;
    }
    return dummy->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == nullptr || root->next == nullptr)
        return root;
    return merge(root, root->next);
}