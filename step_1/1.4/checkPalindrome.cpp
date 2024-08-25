#include <iostream>
#include <math.h>
using namespace std;

bool isPalindrome(int x)
{
    long int rev = 0;
    long int num = x;
    while (num != 0)
    {
        rev = (rev * 10) + num % 10;
        num = num / 10;
    }
    if (pow(-2, 31) <= rev && pow(2, 31) - 1 >= rev)
    {
        if (rev == x && rev >= 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main(int argc, char *argv[])
{
    cout << isPalindrome(121);
    return 0;
}