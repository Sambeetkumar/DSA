#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
        if(n<0) return false;

        return !(log2(n)-ceil(log2(n)));
    }
int main(int argc, char* argv[]) {
    int n;
    cout << "enter a number : ";
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}