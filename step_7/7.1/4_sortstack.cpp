#include <bits/stdc++.h>
using namespace std;
class SortedStack
{
public:
    stack<int> s;
    void sort();
};
void SortedInsert(stack<int> &s, int val)
{
    /*if stack is empty push the val and return the stack*/
    if (s.empty() || s.top() < val)
    {
        s.push(val);
        return;
    }
    else
    {
        //else store the top el and pop it to reduce stack size then again call
        //SortedInsert with updated stack and val
        int temp = s.top();
        s.pop();
        SortedInsert(s, val);
        s.push(temp);
    }
}
void SortedStack ::sort()
{
    /*when we reach at only one el left in stack then return as no need to sort*/
    if (s.size() == 1)
        return;
    /*pop the top el, store it, sort the reduced stack recursively*/
    int temp = s.top();
    s.pop();
    sort();
    //inserting temp in the sorted stack
    SortedInsert(s, temp);
}
int main(int argc, char *argv[])
{
    SortedStack obj1;
    obj1.s.push(41);
    obj1.s.push(3);
    obj1.s.push(32);
    obj1.sort();
    return 0;
}