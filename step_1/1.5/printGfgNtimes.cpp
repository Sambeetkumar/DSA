#include <iostream>
using namespace std;
//print GFG n times using recursion
void printGfg(int N) {
        // Code here
        if(N==0) return;

        cout << "GFG ";
        printGfg(N-1);
    }
int main(int argc, char* argv[]) {

    printGfg(5); // prints GFG GFG GFG GFG GFG

    return 0;
}