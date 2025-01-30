#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverse(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp != nullptr)
    {
        ListNode *nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}
// function that returns a pointer pointing to the kth node
ListNode *getKthNode(ListNode *temp, int k)
{
    k -= 1;
    while (temp != nullptr && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    /*the main idea behind this algo is to break the netire list into chunks
    of size k, reversing them indivisually and then merging them*/
    ListNode *temp = head; // pointer to iterate over the given linked list
    ListNode *prevLast = nullptr;
    while (temp != nullptr)
    {
        // returns kth node starting from temp
        ListNode *kthNode = getKthNode(temp, k);
        if (kthNode == nullptr)
        {
            /*if there are not enough nodes to form a group of k, then point
            the next of last node of previous grp to temp and break*/
            if (prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        // storing the next node of kth node so that we can move ahead
        ListNode *nextNode = kthNode->next;
        /*pointing kthnode->next to null so that we can reverse the group of
        k nodes(from temp to kth node)*/
        kthNode->next = nullptr;
        reverse(temp);
        if (temp == head)
        {
            // the reversed chunk is the first chunk
            head = kthNode;
        }
        else
        {
            /*pointing the next ptr of last node of previous chunk to start of
            currently reversed chunk*/
            prevLast->next = kthNode;
        }
        /*moving prev last to temp*/
        prevLast = temp;
        /*moving temp to next part*/
        temp = nextNode;
    }
    return head;
}