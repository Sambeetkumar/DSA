#include <bits/stdc++.h>
using namespace std;
void pushAtEnd(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    pushAtEnd(st, val);
    st.push(temp);
}
void Reverse(stack<int> &St)
{
    if (St.empty())
        return;
    int temp = St.top();
    St.pop();
    Reverse(St);
    pushAtEnd(St, temp);
}
int main(int argc, char *argv[])
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    Reverse(s);
    return 0;
}