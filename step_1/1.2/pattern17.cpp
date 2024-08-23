#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'A';
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << c;
            if (j < i) c++;
            else c--;
        }
        for (int j = 0; j < n - i - 1; j++)
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