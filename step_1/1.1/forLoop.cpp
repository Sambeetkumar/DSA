#include <iostream>
using namespace std;
//https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int findNthFibonacci(int n)
{
    if (n == 1 || n==2 )
        return 1;
    else
        return findNthFibonacci(n - 1) + findNthFibonacci(n - 2);
}
int main(int argc, char *argv[])
{
    cout << findNthFibonacci(3) << endl;
    return 0;
}
//1 1 2 3 5 8 13...