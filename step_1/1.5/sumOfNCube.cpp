#include <iostream>
using namespace std;

long long sumOfSeries(long long n)
{
    // code here
    if (n == 1) return 1;
    long long sum = n * n * n;

    return sum + sumOfSeries(n - 1);
}

int main(int argc, char *argv[])
{
    cout<< sumOfSeries(10);
    return 0;
}