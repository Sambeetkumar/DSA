#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long long> st;
    //var that holds the current minimum value
    long long mini;
public:
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        //if the stack is empty just push the value and initialze mini variable
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val>mini){
            st.push(val);
        }
        /*when a smaller el than mini comes we don't push that el directly to the stack,
        we will find its hashed value as (2*val-prevMini) so that when it will be popped
        we can retrieve our prev minimum value*/
        else{
            long long newVal = (long long)2*val-mini;
            mini = val;
            st.push(newVal);
        }
    }
    
    void pop() {
       long long newVal = st.top();
       st.pop();
       /*if the top el is less than mini,then that is a hashed value, as it's getting
         popped we need to retrieve our prev minimum value. refer the hashing formula*/
       if(newVal<mini){
          mini = 2*mini-newVal;
       }
    }
    
    int top() {
        long long topEl = st.top();
        //if the topel is less than mini, then it's a hashed value and it's original
        //value is the current minimum value.
        if(topEl<mini){
            topEl = mini;
        }
        return topEl;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */