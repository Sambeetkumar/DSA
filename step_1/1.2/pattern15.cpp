#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        for (char ch='A'; ch <= 'A'+i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    printPattern(5);

    return 0;
}