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
int countNodesinLoop(Node *head)
{
    // Code here
    /*manual check for size 0,1 and 2*/
    if (head == NULL)
        return 0;
    if (head->next == NULL)
        return 0;
    if (head->next->next == NULL)
        return 0;
    /*apply tortoise hare algorithm, if at any point head points to null or last node
    then our iteration have come to an end(no loop).*/
    Node *fast = head->next->next;
    Node *slow = head->next;
    int cnt = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    /*if at any point fast collides with slow, then we are in the loop.keep one pointer const
    and move the other one untill they collide again*/
        if (slow == fast)
        {
            while (cnt == 0 || fast != slow)
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
}
int main(int argc, char *argv[])
{

    return 0;
}