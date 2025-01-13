#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> v,int k) {
    int i = 0, j = 0;
    int n = v.size();
    int sum = 0;//initializing sum to 0
    int maxSum = INT_MIN;
    while(j<n)
    {
        sum += v[j];
        
        if(j-i+1==k)//when we hit window size
        {
            maxSum = max(maxSum, sum);
            sum -= v[i];

            /*once we hit the window size to maintain the window size we need
             to increase pointer i in each step*/
            i++;
        }

        j++;
    }
    return maxSum;
}
int main(int argc, char* argv[]) {
    vector<int> s = {2, 3, 4, 10, 0, 5, 5, 7, 8};
    cout << maxSum(s,3);
}