#include <iostream>
using namespace std;

//Question link - https://bit.ly/3GzvAAa

void printPattern(int n){
    for (int i = 0; i < n; i++)
    {
        for (int a = n-i-1; a > 0; a--){
            cout << " ";
        }
        for (int b = 0; b < 2*i+1; b++){
            cout << "*";
        }
        for (int a = n-i-1; a > 0; a--){
            cout << " ";
        }
        cout << endl;
    }
    
}

int main(int argc, char* argv[]) {

    printPattern(5);
    return 0;
}