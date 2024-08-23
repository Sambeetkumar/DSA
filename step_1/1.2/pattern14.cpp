#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = 65;
        for (int j = 0; j <= i; j++)
        {
            cout << (char)k << " ";
            k++;
        }

        cout << endl;
    }
}
int main(int argc, char *argv[])
{

    printPattern(5);

    return 0;
}