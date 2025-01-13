#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr) {
        int largest = INT_MIN;
        for(auto it:arr)
        {
            if(it>largest)
            largest = it;
        }
        return largest;
    }
int main(int argc, char* argv[]) {
    vector<int> v = {23, 10, 90, 44, 4};
    cout << largest(v);
    return 0;
}