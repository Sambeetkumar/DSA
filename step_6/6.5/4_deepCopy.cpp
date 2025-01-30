#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
        //if there is no node, then no need to clone
        if(head==nullptr) return head;
        //map to hash original nodes to their corresponding new nodes
        unordered_map<Node*,Node*>m;
        Node *newHead = new Node(head->val);
        m[head] = newHead;
        Node* temp1 = head->next;
        Node* temp2 = newHead;
        /*creating a new list simillar to old one whose random pointers are null
        for now and also mapping the address of old nodes with their corresponding
        new nodes*/
        while(temp1!=nullptr)
        {
            Node* newNode = new Node(temp1->val);
            m[temp1] = newNode;
            temp2->next = newNode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = head;
        temp2 = newHead;
        /*now using two pointer approach we will try to place the random pointers
        of new nodes by using the existing hash map*/
        while(temp1!=nullptr)
        {
            if(temp1->random==nullptr)
            temp2->random = nullptr;
            else
            {
                temp2->random = m[temp1->random];
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return newHead;;
    }