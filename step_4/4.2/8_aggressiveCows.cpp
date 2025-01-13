#include <bits/stdc++.h>
using namespace std;

//Optimal approach using binary search O(n*log n)
int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end()); //first sort the stalls vector 
    int e = *max_element(stalls.begin(), stalls.end());
    int s = 1, cows = 0;

    /*performing binary search on range 1 to max element on stalls,
    because the min and max distance between two placement can be 1 
    and max element in stall respectively*/
    while (s <= e)
    {
        /*considering mid as the min dist between two cows, we will start placing them*/
        int mid = s + (e - s) / 2;
        int count = 0, lastCow = 0;
        for (int j = 1; j < n; j++)
        {
            /*if the dist between curr stall and stall where last cow is placed >= min dist,
            then we can place cow in curr stall*/
            if (stalls[j] - stalls[lastCow] >= mid)
            {
                count++;
                lastCow = j;
            }
        }
        //calculating tot no of cows placed considering mid as min distance
        cows = count + 1;
        /*if value of placed cows >= k, then we have to increase the min distance, so eliminate
        left half*/
        if (cows >= k)
        {
            s = mid + 1;
        }
        //else eliminate right half
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

//brute force approach

// int solve(int n, int k, vector<int> &stalls)
// {
//     int e = *max_element(stalls.begin(), stalls.end());
//     sort(stalls.begin(), stalls.end());
//     int dist = e;

//     for (int i = 1; i <= e; i++)
//     {
//         int count = 0, lastCow =0;
//         for (int j = 1; j < n; j++)
//         {
//             if(stalls[j]-stalls[lastCow]>=i)
//             { 
//               count++;
//               lastCow = j;
//             }

//         }
//         if(count+1 < k)
//         {
//             dist = i-1;
//             break;
//         }
//     }
//     return dist;
// }
int main(int argc, char *argv[])
{
    vector<int> v = {4,2,1,3,6};
    cout << solve(v.size(), 2, v);

    return 0;
}