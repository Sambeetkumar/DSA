#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int>& a) {
        // code here
        long long n = a.size();// size of the array

    // Find Sn(sum of 1st n natural numbers) and S2n(sum of sqr of 1st n natural numbers):
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S(sum of els in the array) and S2(sum of sqr of them):
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    //let X= repeating number, Y = missing number
    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
    }
int main(int argc, char* argv[]) {
    vector<int> v = {1, 2, 3, 3, 5};
    for(auto it:findTwoElement(v))
    {
        cout << it << " ";
    }
    return 0;
}