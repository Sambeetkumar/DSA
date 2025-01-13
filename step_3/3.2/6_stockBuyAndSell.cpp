#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
     
     int maxProf = INT_MIN;
     int maxi = INT_MIN;
     int n = prices.size();
     for(int i=n-1; i>=0; i--)
     {
        /*storing the maximum value between value pointed by i and end of the array*/
        maxi=max(maxi,prices[i]);
        /*updating max profit by calculating profit if we buy stock at current index and
        sell it value stored in maxi*/
        maxProf = max(maxProf,maxi-prices[i]);
     }
     return maxProf;
    }
int main(int argc, char* argv[]) {

    vector<int> v = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(v);
    return 0;
}