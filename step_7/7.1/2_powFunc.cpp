#include <iostream>
using namespace std;
double myPow(double x, long long n)
{
    if (x == 1)
        return 1;
    // if we reach at the end of the recursion where power becomes 0 then return 1;
    if (n == 0)
        return 1;
    // handiling negative power
    if (n < 0)
        return 1 / myPow(x, -n);
    /*if power is odd store an instance of x to make power even, then call the func
    by squaring x and making the power half*/
    if (n & 1)
    {
        double ans = x;
        return ans * myPow(x * x, (n - 1) / 2);
    }
    else
        // if power is even no need to store an instance of x
        return myPow(x * x, n / 2);
}
int main()
{
    cout << myPow(2, 10);
}