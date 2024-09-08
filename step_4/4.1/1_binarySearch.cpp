#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v,int low,int high,int target)
{
    if(low>high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if(v[mid]==target)
            return mid;
        else if(v[mid]>target)
            return binarySearch(v, low, mid - 1, target);
        else
            return binarySearch(v, mid + 1, high, target);
    }
}
int main(int argc, char* argv[]) {
    vector<int> v = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << binarySearch(v, 0, v.size() - 1,6);
    return 0;
}