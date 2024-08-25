#include <iostream>
#include <math.h>
using namespace std;
string armstrongNumber(int n)
{
    int num = 0, num2 = n;
    while (num2 != 0)
    {
        num = num + pow(num2 % 10, 3);
        num2 /= 10;
    }
    if (num == n)
        return "true";
    else
        return "false";
}
int main(int argc, char *argv[])
{

    cout << armstrongNumber(153);

    return 0;
}