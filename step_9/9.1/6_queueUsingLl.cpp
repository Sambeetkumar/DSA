#include <bits/stdc++.h>
using namespace std;

 //Definition of linked list
 class Node {

 public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
 };

 //Definition of Queue
 struct Queue {
   Node* front;
   Node* rear;
   void push(int);
   int pop();   
   Queue() {
       front = rear = NULL;
   }
  };

void Queue::push(int x) {
    // Write Your Code Here
    Node *newnode = new Node(x);
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next = newnode;
        rear = rear->next;
    }
}

int Queue::pop() {
    // Write Your Code Here
    if(front==NULL && rear==NULL)
    return -1;
    int val = front->data;
    if(front==rear){
        front=NULL;
        rear=NULL;
    }
    else{
        front=front->next;
    }
    return val;
}