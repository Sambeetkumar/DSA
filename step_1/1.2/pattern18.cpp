#include <iostream>
using namespace std;

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n-1);
        ch = ch - i;
        for (int j = i; j >= 0; j--)
        {
            cout << ch<< " ";
            ch++;
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    printPattern(3);
    return 0;
}