#include <iostream>
using namespace std;

void printPattern(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
int main(int argc, char* argv[]) {

    printPattern(5);
    return 0;
}