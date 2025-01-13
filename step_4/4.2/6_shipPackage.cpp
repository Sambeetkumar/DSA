#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    /*binary search range will be max el of weights to sum of all waights*/
    int s = *max_element(weights.begin(), weights.end()), e = accumulate(weights.begin(), weights.end(), 0);
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int count = 0, sum = 0;
        for (int j = 0; j < weights.size(); j++)
        {
            sum = sum + weights[j];//adding weights to sum one by one
            if (sum >= mid)
            {
                /*when we reach our capacity increase count by 1 as one day is passed*/
                count++;
                /*if sum > capacity we should exclude the latest weight*/
                if (sum > mid)
                    j = j - 1;
                sum = 0;
            }
        }
        /*if number of days used is <= required we should decrease our capacity, so 
        eliminate right half. else eliminate left half*/
        if (sum == 0 ? count <= days : count + 1 <= days)
            e = mid - 1;
        else
            s = mid + 1;
    }
    /*becasue of opposite polarity, at the end of bs s will point to the min capacity to ship
    with in required days*/
    return s;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 2, 3, 1, 1};
    cout << shipWithinDays(v, 4);
    return 0;
}