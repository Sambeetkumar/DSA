#include <iostream>
using namespace std;

void printNos(int N)
{
    // code here
    if (N < 1)
        return;

    cout << N << " ";
    printNos(N - 1);
}

int main(int argc, char *argv[])
{
    printNos(10);
    return 0;
}