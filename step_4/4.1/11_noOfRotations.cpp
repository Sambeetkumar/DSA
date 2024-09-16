#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/rotation4723/1

int findKRotation(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1, minIndex = 0, min = INT32_MAX;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        // if the search space is sorted
        if (arr[s] <= arr[e])
        {
            /* compare the minimum element with the prev minimum,
            if it is smaller then store the index of minimum element*/
            if (min > arr[s])
            {
                min = arr[s];
                minIndex = s;
            }
            break;
        }

        // if the left half is sorted
        else if (arr[s] <= arr[mid])
        {
            /* compare the minimum element with the prev minimum,
            if it is smaller then store the index of minimum element*/
            if (min > arr[s])
            {
                minIndex = s;
                min = arr[s];
            }

            s = mid + 1; //eliminate the left half
        }
        else //if the right half is sorted
        {
            if (min > arr[mid])
            {
                minIndex = mid;
                min = arr[mid];
            }

            e = mid - 1; //eliminate the right half
        }
    }

    return minIndex; //returning index of minimum element
}
int main(int argc, char *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << findKRotation(v);

    return 0;
}