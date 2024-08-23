#include <iostream>
using namespace std;

void printPattern(int n){
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++){
            cout << k << " ";
            k++;
        }

        cout << endl;
    }
    
}

int main(int argc, char* argv[]) {

    printPattern(5);
    return 0;
}