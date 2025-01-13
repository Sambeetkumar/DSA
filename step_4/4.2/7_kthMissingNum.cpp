#include <iostream>
#include <vector>
using namespace std;

// int findKthPositive(vector<int> &arr, int k)
// {
//     int t = 0, i = 0;
//     int n = arr.size();
//     vector<bool> v(arr[n-1]+k, false);
//     cout << arr.size() << endl;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         v[arr[i]-1] = true;
//     }
//     while (t < k)
//     {
//         if (v[i] == false)
//         {
//             t++;
//         }

//         i++;
//     }
//     return i;
// }

int findKthPositive(vector<int>& arr, int k)
{
    int n = arr.size();
    //calculate tot missing numbers inside the array
    int missingInside = arr[n - 1] - arr.size();
    if(missingInside<k)
    {
        return (arr[n - 1] + (k - missingInside));
    }
    else
    {
        int s = 0, e = n - 1;
        while(s<=e)
        {
            int mid = s + (e - s) / 2;
            //calculate tot missing numbers between start and el pointed by mid 
            int missing = arr[mid] - mid - 1;
            /*if the required missing number <= missing then our ans lies in the left half
            otherwise in the right half*/
            if(k<=missing)
                e = mid - 1;
            else
                s = mid + 1;
        }
        /*at the end of bs our required el lies between el pointed by e and el pointed by s
        the formula to the find that number is arr[e]+(K-(arr[e]-e-1))*/
        return (k + e + 1);
    }
    return 0;
}
int main(int argc, char *argv[])
{
    vector<int> v = {4,7,9};
    cout << findKthPositive(v, 4);

    return 0;
}