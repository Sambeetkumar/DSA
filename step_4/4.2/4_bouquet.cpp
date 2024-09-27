#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

//returns min and max element of the given vector
pair<int,int> findMaxMin(vector<int> v, int n)
{
    int max= v[0], min = v[0];
    for (int i = 0; i < n; i++)
    {
        if (max < v[i])
            max = v[i];
        if (min > v[i])
            min = v[i];
    }
    return {min,max};
}

//func to find min days required
int minDays(vector<int> &bloomDay, int m, int k)
{
    int size = bloomDay.size();
    long long tot = long(m) * long(k);//total no of flowers required

    /*if size of bloomDay is smaller than the no of flowers required then
     it's the impossible case*/
    if (size < tot)
        return -1;

    pair<int,int> p = findMaxMin(bloomDay, size);
    int s = p.first, e = p.second, ans = -1;
    //perform bs on the range (lowest day to the highest day)
    while (s <= e)
    {
        int bouquet = m;//no of bouquets required
        int mid = s + (e-s) / 2;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            /*if bloomDay[i] <= mid, then the flower must be blown, increase the count by 1*/
            if (bloomDay[i] <= mid)
            {
                count++;
                /*if count becomes the no of flowers required for one bouquet then set count
                 to 0 and dec bouquet by 1 as one bouquet is completed*/
                if (count == k)
                {
                    count = 0;
                    bouquet--;
                }
            }
            /*if bloomDay[i] > mid then flower is yet to bloom, continuity breaks so set count to 0*/
            else
            {
                count = 0;
            }
        }
        /*if bouquet <= 0 then total no of bouquet required is complete, store the mid and eliminate the right half*/
        if (bouquet <= 0)
        {
            ans = mid;
            e = mid - 1;
        }
        /*else eliminate the left half*/
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main(int argc, char *argv[])
{
    vector<int> v = {2,3,2,2,4,4,9,1,1,5,10};
    int m = 2, k = 4;
    cout << minDays(v, m, k);

    return 0;
}