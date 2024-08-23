#include <iostream>
using namespace std;
// Question link - https://bit.ly/3Gzv70S
void printPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int a = 5;
    printPattern(a);

    return 0;
}