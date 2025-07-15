#include <iostream>
using namespace std;
int xr(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    if (n % 4 == 0)
        return n;
}
int findXOR(int l, int r)
{
    // complete the function here
    return xr(l - 1) ^ xr(r);
}
int main(int argc, char *argv[])
{
    int l, r;
    cout << "Enter l, r: ";
    cin >> l >> r;
    cout << findXOR(l, r);
    return 0;
}