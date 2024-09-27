#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

//function to find ceil value
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

//func to maximum value in an array
int findMax(vector<int> v, int n)
{
    int max = v[0];
    for (int i = 0; i < n; i++)
    {
        if (max < v[i])
            max = v[i];
        
    }
    return max;
}

int smallestDivisor(vector<int> &nums, int threshold)
{

    int size = nums.size();
    int max = findMax(nums, size);
    int s = 1, e = max;
    
    //perform bs from 1 to max value in nums
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        int res = 0;

        //find the sum of divisions's result
        for (auto it : nums)
        {
            res = res + getCeil((float)it / mid);
        }

        //if res <= threshold then that might be the answer, eliminate the right half
        if(res<=threshold)
        {
            e = mid - 1;
        }
        /*if res > threshold, eliminate the left half because for all values in the left half
        res will be beyond threshold*/
        else
        {
            s = mid + 1;
        }
    }
    return s;
}
int main(int argc, char *argv[])
{
    vector<int> v = {21212,10101,12121};
    cout << smallestDivisor(v, 1000000);

    return 0;
}