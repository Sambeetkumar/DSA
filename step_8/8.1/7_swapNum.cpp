#include <bits/stdc++.h>
using namespace std;
void swapNumber(int &a, int &b) {
	// Write your code here.
	a = a^b;
	b = b^a;
	a = a^b;
}
int main(){
    int a = 8;
    int b = 3;
    cout << "Before swap a = " << a << " b = " << b << endl;
    swapNumber(a, b);
    cout << "After swap a = " << a << " b = " << b << endl;
    return 0;
}