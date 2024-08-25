#include <iostream>
#include <math.h>
using namespace std;

long int reverse(int x)
{
  long int rev = 0;
  while (x != 0)
  {
    rev = (rev * 10) + x % 10;
    x /= 10;
  }
  if (pow(-2, 31) <= rev && pow(2, 31) - 1 >= rev)
    return rev;
  else
    return 0;
}
int main(int argc, char *argv[])
{
  cout<< reverse(123456789);
  return 0;
}