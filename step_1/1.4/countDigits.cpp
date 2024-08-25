#include <bits/stdc++.h>
using namespace std;
int evenlyDivides(int N)
{
    vector<int> v;
    int c = N;
    int rem;
    while (c != 0)
    {
        rem = c % 10;
        if (rem != 0)
        {
            v.push_back(rem);
        }
        c /= 10;
    }
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (N % *it == 0)
            c++;
    }
    return c;
}
int main(int argc, char *argv[])
{
    cout << evenlyDivides(2206);

    return 0;
}