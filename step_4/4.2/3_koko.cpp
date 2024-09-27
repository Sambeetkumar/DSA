#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/koko-eating-bananas/description/

//function to find ceil of a value
int getCeil(double x)
{
    int int_part = (int)x;

    if (x == int_part)
    {
        return int_part;
    }
    else
    {
        return int_part + 1;
    }
}

int minEatingSpeed(vector<int> &piles, int h)
{
    //find out the maximum element in piles
    int max = piles[0];
    for (auto it : piles)
    {
        if (max < it)
            max = it;
    }

    //perform bs from 1 to max
    int s = 1, e = max, ans = 0;
    while (s <= e)
    {
        int t = 0;
        int mid = s + (e - s) / 2;
        //calculate total time taken by k=mid
        for (auto it : piles)
        {
            t = t + getCeil((double)it / mid);
        }
        
        //if it t <= h then that might be the ans, store it and move left.
        if (t <= h)
        {
            ans = mid;
            e = mid - 1;
        }
        else // if t>h then move right in order to reduce the value of t.
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> v = {1,1,1,999999999};
    cout << minEatingSpeed(v, 10);

    return 0;
}