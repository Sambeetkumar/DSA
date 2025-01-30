#include <bits/stdc++.h>
using namespace std;
int myPow(long long x, long long nn)
{
    long long ans = 1;

    long long modu = pow(10, 9) + 7;
    while (nn > 0)
    {
        if ((nn & 1) == 0)
        {
            x = (x * x) % modu;
            nn = nn / 2;
        }
        else
        {
            ans = (ans * x) % modu;
            nn--;
        }
    }

    return ans;
}
int countGoodNumbers(long long n)
{
    long long evenPlaces = 0, oddPlaces = 0;
    oddPlaces = n / 2;
    evenPlaces = n - oddPlaces;
    long long mod = pow(10, 9) + 7;
    long long temp1 = myPow(4, oddPlaces);
    long long temp2 = myPow(5, evenPlaces);
    long long ans = (long long)temp1 * temp2;
    ans = ans % mod;
    return ans;
}
int main(int argc, char *argv[])
{
    int n = 5;
    cout << countGoodNumbers(n);

    return 0;
}