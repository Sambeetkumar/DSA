#include <bits/stdc++.h>
using namespace std;

// Approach 1
// vector<int> leaders(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> v(n, 0);
//     vector<int> ans;
//     v[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         v[i] = max(arr[i], v[i + 1]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (v[i] == arr[i])
//             ans.push_back(v[i]);
//     }
// }

// Approach 2

vector<int> leaders(vector<int> &arr)
{

    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        /*iterating from right and storing the max value between n-1 and index i*/
        maxi = max(maxi, arr[i]);
        //if i points to the latest max el, then all el to the right are smaller
        if (arr[i] == maxi)
            ans.push_back(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> v = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders(v);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}