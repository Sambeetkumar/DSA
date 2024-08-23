#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - (i + 1)); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    printPattern(5);

    return 0;
}