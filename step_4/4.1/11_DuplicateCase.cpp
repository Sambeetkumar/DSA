#include <iostream>
#include <vector>
using namespace std;

int findKRotation(vector<int> &arr) {
    int s = 0, e = arr.size() - 1, minIndex = 0, min=INT32_MAX;
    while(s<=e)
    {
        int mid = (s + e) / 2;
        if(arr[s]==arr[mid] && arr[mid]==arr[e])
        {
            if(min>arr[mid])
            {
                min = arr[mid];
                minIndex = mid;
            }
            
            s=s+1,e=e-1;
        }
        else if (arr[s]<=arr[mid])
        {
            if(min>arr[s])
            {
                minIndex = s;
                min = arr[s];
            }

            s = mid + 1;
        }
        else
        {
            if(min>arr[mid])
            {
                minIndex = mid;
                min = arr[mid];
            }
            
            e = mid - 1; 
        }
    }

    return minIndex;
}
int main(int argc, char* argv[]) {
    vector<int> v = {1, 1, 0, 1, 1, 1};

    cout << findKRotation(v);

    return 0;
}