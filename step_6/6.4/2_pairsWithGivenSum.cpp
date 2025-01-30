#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {}
};
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    // moving tail to the end
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    //perform check untill head and tail meet each other
    while (head->data < tail->data)
    {
        int sum = head->data + tail->data;
        //if sum == pair then store it and move head forward and tail backward
        if (sum == target)
        {
            ans.push_back({head->data, tail->data});
            head = head->next;
            tail = tail->prev;
        }
        //if sum > target, then inorder to reach towards sum we need to decrease our sum value
        else if (sum > target)
        {
            tail = tail->prev;
        }
        //else increase sum value
        else
        {
            head = head->next;
        }
    }
    return ans;
}