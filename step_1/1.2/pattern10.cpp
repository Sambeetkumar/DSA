#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - (i + 1); j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++)
    {
        cout << "*";
    }

    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - (i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    printPattern(5);
    return 0;
}