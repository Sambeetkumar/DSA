#include <bits/stdc++.h>
using namespace std;

// double minimiseMaxDistance(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     vector<int> howMany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;
//     for (int i = 0; i < n - 1; i++)
//     {
//         long double diff = arr[i + 1] - arr[i];
//         pq.push({diff, i});
//     }
//     while (k--)
//     {
//         auto tp = pq.top();
//         pq.pop();
//         int secInd = tp.second;
//         howMany[secInd]++;
//         long double diff = arr[secInd + 1] - arr[secInd];
//         long double newSecLen = diff / (double)(howMany[secInd] + 1);

//         pq.push({newSecLen, secInd});
//     }

//     return pq.top().first;
// }
int noOfGasStation(long double dist, vector<int> &arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int inside = (arr[i] - arr[i - 1]) / dist;
        if((arr[i] - arr[i - 1])==(inside*dist))
        {
            inside--;
        }
        count += inside;
    }
    return count;
}
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int req = noOfGasStation(mid, arr);
        
        if (req > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 13, 17, 23};
    cout << minimiseMaxDistance(v, 5);

    return 0;
}