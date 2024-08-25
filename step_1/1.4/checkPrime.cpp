#include <iostream>
using namespace std;

string isPrime(int n){
    int c = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0) c++;
    }
    if (c == 2) return "true";
    else return "false";
}

int main(int argc, char* argv[]) {
    cout << isPrime(10);

    return 0;
}