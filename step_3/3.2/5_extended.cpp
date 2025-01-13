#include <bits/stdc++.h>
using namespace std;

int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int score = INT_MIN;
        int sum=0;
        int i = 0, j = 0;
        int n = arr.size();
        while(j<n)
        {
            sum += arr[j];
            while(j-i+1==2)
            {
                score = max(score, sum);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return score;
    }
int main(int argc, char* argv[]) {
    vector<int> v = {5, 4, 3, 1, 6};
    cout<< pairWithMaxSum(v);
    return 0;
}