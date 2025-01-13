#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

    return arr;
}
int main(int argc, char* argv[]) {

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = rotateArray(v1,v1.size());
    for(auto it: v2)
    {
        cout << it << " ";
    }

    return 0;
}