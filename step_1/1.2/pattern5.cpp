#include <iostream>
using namespace std;
//Question link - https://bit.ly/3WXGSDD
void printPattern(int n){
for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    int a = 5;
    printPattern(a);

    return 0;
}