#include <iostream>
using namespace std;
//Question link - https://bit.ly/3QfK2k3
void printPattern(int n){
for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int a;
    cout << "enter a number : ";
    cin >> a;
    printPattern(a);

    return 0;
}