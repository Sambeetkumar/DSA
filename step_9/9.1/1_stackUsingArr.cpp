#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack {
    int *arr;
    int topi;
    int capacity;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->capacity = capacity;
        arr = new int[capacity];
        topi = -1;
    }

    void push(int num) {
        // Write your code here.
        if(topi!=capacity-1){
            topi++;
            arr[topi]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(topi==-1) return -1;
        int topEl = arr[topi];
        topi--;
        return topEl;
    }
    
    int top() {
        // Write your code here.
        if(topi==-1) return -1;
        return arr[topi];
    }
    
    int isEmpty() {
        // Write your code here.
        return topi==-1;
    }
    
    int isFull() {
        // Write your code here.
        return topi==capacity-1;
    }
};
