#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<long long> &v, long long n, long long x) {

        int low=0,high = n-1,ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]>x)
            {
                high = mid-1;
            }
            else
            {
                low=mid+1;
                ans=mid;
            }
        }
        return ans;
    }

int main(int argc, char* argv[]) {
    vector<long long> v = {1, 2, 8, 10, 11, 12, 19};
    int x = 5;
    cout << findFloor(v, v.size(), x);

    return 0;
}