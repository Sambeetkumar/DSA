#include <iostream>
using namespace std;

long long int floorSqrt(long long int n) {
        /*sqrt of a number can lie between 1 to n (the number itself)
        so we will perform binary search of the sqrt on the search space 1 to n*/
        int s=1,e=n,ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            //if mid lands on sqrt of the number
            if((mid*mid)==n)
            return mid;

            /*if mid^2 > n, then that can't be the sqrt and sqrt lies on left of mid, so 
            eliminate the right half*/
            else if((mid*mid)>n)
            e=mid-1;

            /*if mid^2 < n, then that can be the floor(sqrt), store and eliminate the left half*/
            else
            {
            ans=mid;
            s=mid+1;
            }
        }
        return ans;
    }
int main(int argc, char* argv[]) {
    cout << floorSqrt(64);

    return 0;
}